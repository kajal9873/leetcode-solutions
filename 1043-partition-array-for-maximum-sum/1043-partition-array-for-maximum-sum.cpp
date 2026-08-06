class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1,0);
        for(int i=1; i<=n; i++){
            int currmax = 0;
            for(int l=1; l<=k && l<=i; l++){
                currmax = max(currmax, arr[i-l]);
                dp[i] = max(dp[i], dp[i-l]+currmax*l);
            }
        }
        return dp[n];
    }
};