class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9+7;
        int n = s.size();
        vector<long long> dp(n+1,0);
        vector<int> last(26,-1);
        dp[0] = 0;
        for(int i=1; i<=n; i++){
            char c = s[i-1];
            int idx = c - 'a';
            dp[i] = (2*dp[i-1]%MOD + 1)%MOD;
            if(last[idx]!=-1){
                dp[i] = (dp[i] - dp[last[idx]-1] - 1 + MOD)%MOD;
            }
            last[idx] = i;
        }
        return (int)dp[n];
    }
};