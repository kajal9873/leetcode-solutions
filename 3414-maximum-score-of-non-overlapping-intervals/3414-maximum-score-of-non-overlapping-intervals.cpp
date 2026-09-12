#include <bits/stdc++.h>
using namespace std;

struct State {
    long long score = 0;
    int cnt = 0;
    int idx[4] = {0,0,0,0};   // sorted ascending original indices
};

// true if 'cand' is strictly better than 'cur'
bool isBetter(const State &cand, const State &cur) {
    if (cand.score != cur.score) return cand.score > cur.score;
    int m = min(cand.cnt, cur.cnt);
    for (int i = 0; i < m; i++)
        if (cand.idx[i] != cur.idx[i]) return cand.idx[i] < cur.idx[i];
    return cand.cnt < cur.cnt;  // shorter (prefix) is lexicographically smaller
}

class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        // (l, r, w, originalIndex)
        vector<array<long long,4>> iv(n);
        for (int i = 0; i < n; i++)
            iv[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};

        sort(iv.begin(), iv.end(), [](auto &a, auto &b){ return a[0] < b[0]; });

        vector<long long> Ls(n);
        for (int i = 0; i < n; i++) Ls[i] = iv[i][0];

        vector<int> nxt(n);
        for (int i = 0; i < n; i++) {
            long long r = iv[i][1];
            nxt[i] = upper_bound(Ls.begin(), Ls.end(), r) - Ls.begin();
        }

        vector<array<State,5>> dp(n + 1);  // dp[n][*] = default (score0, empty)

        for (int i = n - 1; i >= 0; i--) {
            long long w = iv[i][2];
            int origIdx = (int)iv[i][3];
            int j = nxt[i];
            for (int k = 1; k <= 4; k++) {
                State best = dp[i + 1][k];          // skip current interval
                State comp = dp[j][k - 1];          // take current interval

                State cand;
                cand.score = comp.score + w;
                cand.cnt = comp.cnt + 1;

                // merge origIdx into sorted comp.idx[]
                int p = 0;
                while (p < comp.cnt && comp.idx[p] < origIdx) {
                    cand.idx[p] = comp.idx[p];
                    p++;
                }
                cand.idx[p] = origIdx;
                for (int t = p; t < comp.cnt; t++) cand.idx[t + 1] = comp.idx[t];

                dp[i][k] = isBetter(cand, best) ? cand : best;
            }
            // dp[i][0] stays default (score 0, empty) automatically
        }

        State ans = dp[0][4];
        return vector<int>(ans.idx, ans.idx + ans.cnt);
    }
};