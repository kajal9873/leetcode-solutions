class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int freshcount = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==2) q.push({i,j});
                else if(grid[i][j]==1) freshcount++;
            }
        }
        if(freshcount==0) return 0;
        int minutes = 0;
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        while(!q.empty() && freshcount>0){
            int size = q.size();
            for(int i=0; i<size; i++){
                auto [r,c] = q.front();
                q.pop();
                for(int d=0; d<4; d++){
                    int nr = r + dx[d];
                    int nc = c + dy[d];
                    if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1){
                        grid[nr][nc]=2;
                        freshcount--;
                        q.push({nr,nc});
                    }
                }
            }
            minutes++;
        }
        return freshcount==0 ? minutes : -1;
    }
};