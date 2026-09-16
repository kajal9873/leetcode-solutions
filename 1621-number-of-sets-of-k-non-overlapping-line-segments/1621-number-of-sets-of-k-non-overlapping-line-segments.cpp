class Solution {
public:
    int numberOfSets(int n, int k) {
        const long long MOD = 1'000'000'007LL;
        
        // prev holds dp[j-1][*], curr holds dp[j][*]
        vector<long long> prev(n + 1, 1LL); // dp[0][i] = 1 for all i
        vector<long long> curr(n + 1, 0LL);
        vector<long long> prefix(n + 1, 0LL);
        
        for (int j = 1; j <= k; ++j) {
            // prefix[i] = sum_{m=0}^{i} prev[m]  (mod)
            prefix[0] = prev[0];
            for (int i = 1; i <= n; ++i) {
                prefix[i] = (prefix[i - 1] + prev[i]) % MOD;
            }
            
            curr[0] = 0;
            long long sub = prev[0]; // dp[j-1][0]: 1 only if j-1==0, else 0
            for (int i = 1; i <= n; ++i) {
                long long add = (prefix[i - 1] - sub % MOD + MOD) % MOD;
                curr[i] = (curr[i - 1] + add) % MOD;
            }
            
            swap(prev, curr);
        }
        
        return static_cast<int>(prev[n] % MOD);
    }
};