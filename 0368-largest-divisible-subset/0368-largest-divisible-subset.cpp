class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return {};
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1);
        vector<int> parent(n,-1);
        int maxlen = 1;
        int maxindex = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j]==0){
                    if(dp[j]+1>dp[i]){
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                    }
                }
            }
            if(dp[i]>maxlen){
                maxlen = dp[i];
                maxindex = i;
            }
        }
        vector<int> result;
        int curr = maxindex;
        while(curr!=-1){
            result.push_back(nums[curr]);
            curr = parent[curr];
        }
        reverse(result.begin(),result.end());
        return result;
    }
};