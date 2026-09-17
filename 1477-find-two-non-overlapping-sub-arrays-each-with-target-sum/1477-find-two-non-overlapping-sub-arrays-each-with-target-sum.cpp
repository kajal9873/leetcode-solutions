class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = INT_MAX / 2;
        
        vector<int> best(n, INF); // best[i] = shortest valid subarray length within arr[0..i]
        int ans = INF;
        
        long long sum = 0;
        int left = 0;
        
        for (int right = 0; right < n; ++right) {
            sum += arr[right];
            
            // Shrink window while sum exceeds target (all positive, so this works)
            while (sum > target && left <= right) {
                sum -= arr[left];
                ++left;
            }
            
            if (sum == target) {
                int len = right - left + 1;
                
                // Try to pair with the best subarray ending before 'left'
                if (left > 0 && best[left - 1] < INF) {
                    ans = min(ans, best[left - 1] + len);
                }
                
                // Update running best for prefix ending at 'right'
                best[right] = (right > 0) ? min(best[right - 1], len) : len;
            } else {
                // Propagate previous best forward if no new valid window found at 'right'
                best[right] = (right > 0) ? best[right - 1] : INF;
            }
        }
        
        return (ans >= INF) ? -1 : ans;
    }
};