class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> ispalin(n, vector<bool>(n,false));
        for(int i=0; i<n; i++){
            ispalin[i][i] = true;
        }
        for(int len=2; len<=n; len++){
            for(int i=0; i+len-1<n; i++){
                int j = i+len-1;
                if(s[i]==s[j]){
                    if(len==2 || ispalin[i+1][j-1]){
                        ispalin[i][j] = true;
                    }
                }
            }
        }
        vector<int> dp(n,0);
        for(int i=0; i<n; i++){
            if(ispalin[0][i]){
                dp[i] = 0;
                continue;
            }
            dp[i] = i;
            for(int j=1; j<=i; j++){
                if(ispalin[j][i]){
                    dp[i] = min(dp[i],dp[j-1]+1);
                }
            }
        }
        return dp[n-1];
    }
};