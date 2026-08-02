class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size()/2;
        long long total = 0;
        for(int x : nums) total += x;
        vector<int> left(nums.begin(), nums.begin()+n);
        vector<int> right(nums.begin()+n, nums.end());
        vector<vector<long long>> leftsum(n+1), rightsum(n+1);
        generatesubset(left, leftsum);
        generatesubset(right, rightsum);
        for(int k=0; k<=n; k++){
            sort(rightsum[k].begin(),rightsum[k].end());
        }
        long long best = LLONG_MAX;
        for(int k=0; k<=n; k++){
            for(long long ls : leftsum[k]){
                auto& vec = rightsum[n-k];
                if(vec.empty()) continue;
                double wanted = (total/2.0) - ls;
                int idx = lower_bound(vec.begin(), vec.end(), wanted) - vec.begin();
                for(int di=-1; di<=0; di++){
                    int j = idx + di;
                    if(j>=0 && j<(int)vec.size()){
                        long long sum = ls + vec[j];
                        long long diff = llabs(total-2*sum);
                        best = min(best,diff);
                    }
                }
            }
        }
        return (int)best;
    }
private:
    void generatesubset(vector<int>& arr, vector<vector<long long>>& sum){
        int m = arr.size();
        for(int mask=0; mask<(1<<m); mask++){
            int cnt = __builtin_popcount(mask);
            long long s = 0;
            for(int i=0; i<m; i++){
                if(mask & (1<<i)) s += arr[i];
            }
            sum[cnt].push_back(s);
        }
    }
};