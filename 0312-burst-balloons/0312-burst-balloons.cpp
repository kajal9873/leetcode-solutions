class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> points(n+2);
        points[0] = 1;
        points[n+1] = 1;
        for(int i=0; i<n; i++){
            points[i+1] = nums[i];
        }
        int m = points.size();
        vector<vector<int>> dp(m, vector<int>(m,0));
        for(int len=2; len<m; len++){
            for(int i=0; i+len<m; i++){
                int j = i+len;
                for(int k=i+1; k<j; k++){
                    int coins = dp[i][k] + dp[k][j] + points[i]*points[k]*points[j];
                    dp[i][j] = max(dp[i][j],coins); 
                }
            }
        }
        return dp[0][m-1];
    }
};