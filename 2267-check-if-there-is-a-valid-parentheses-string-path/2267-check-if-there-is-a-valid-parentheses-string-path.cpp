class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if ((m + n - 1) & 1) return false;
        if (grid[0][0] == ')' || grid[m-1][n-1] == '(') return false;

        const int K = 101;
        vector<bitset<K>> dp(n);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                bitset<K> cur;
                if (i == 0 && j == 0) {
                    cur[0] = 1;              // starting balance 0 before applying cell
                } else {
                    if (i > 0) cur |= dp[j];       // from top
                    if (j > 0) cur |= dp[j - 1];   // from left
                }
                if (grid[i][j] == '(') cur <<= 1;
                else                   cur >>= 1;  // bit 0 falls off -> negative balance rejected
                dp[j] = cur;
            }
        }
        return dp[n - 1][0];
    }
};