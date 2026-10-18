class Solution {
    static constexpr int MOD = 1'000'000'007;
    vector<vector<int>> C;

    long long dfs(const vector<int>& v) {
        int m = v.size();
        if (m <= 2) return 1;

        vector<int> left, right;
        left.reserve(m);
        right.reserve(m);
        for (int i = 1; i < m; ++i)
            (v[i] < v[0] ? left : right).push_back(v[i]);

        long long res = C[m - 1][left.size()];
        res = res * dfs(left) % MOD;
        res = res * dfs(right) % MOD;
        return res;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        C.assign(n + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= n; ++i) {
            C[i][0] = 1;
            for (int j = 1; j <= i; ++j)
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
        return (dfs(nums) - 1 + MOD) % MOD;
    }
};