class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
         int m = classroom.size(), n = classroom[0].size();
        int sr = -1, sc = -1;
        vector<pair<int,int>> litterPos; // store positions of all 'L'

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char c = classroom[i][j];
                if (c == 'S') { sr = i; sc = j; }
                else if (c == 'L') litterPos.push_back({i, j});
            }
        }

        int L = litterPos.size();
        if (L == 0) return 0; // nothing to collect

        // map each litter cell -> its bit index, for O(1) lookup during BFS
        vector<vector<int>> litterIdx(m, vector<int>(n, -1));
        for (int i = 0; i < L; i++)
            litterIdx[litterPos[i].first][litterPos[i].second] = i;

        int E = energy;
        int maskCount = 1 << L;
        int fullMask = maskCount - 1;

        // Encode state (r, c, e, mask) -> single integer for compact storage
        auto encode = [&](int r, int c, int e, int mask) {
            return ((r * n + c) * (E + 1) + e) * maskCount + mask;
        };

        long long totalStates = (long long)m * n * (E + 1) * maskCount;
        vector<bool> visited(totalStates, false);

        queue<int> q;
        int startCode = encode(sr, sc, E, 0);
        visited[startCode] = true;
        q.push(startCode);

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        int moves = 0;

        while (!q.empty()) {
            int levelSize = q.size();
            for (int k = 0; k < levelSize; k++) {
                int code = q.front(); q.pop();

                // decode
                int mask = code % maskCount; code /= maskCount;
                int e    = code % (E + 1);   code /= (E + 1);
                int c    = code % n;
                int r    = code / n;

                if (mask == fullMask) return moves; // all litter collected!

                if (e == 0) continue; // energy exhausted, can't move further

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d], nc = c + dc[d];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                    char cell = classroom[nr][nc];
                    if (cell == 'X') continue; // obstacle

                    int ne = (cell == 'R') ? E : e - 1; // reset or consume energy
                    int nmask = mask;
                    if (cell == 'L' && litterIdx[nr][nc] != -1)
                        nmask |= (1 << litterIdx[nr][nc]);

                    int ncode = encode(nr, nc, ne, nmask);
                    if (!visited[ncode]) {
                        visited[ncode] = true;
                        q.push(ncode);
                    }
                }
            }
            moves++; // move to next BFS layer
        }

        return -1; // queue exhausted, all litter never collected
    }
};