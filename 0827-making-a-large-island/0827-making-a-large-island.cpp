class Solution {
public:
    int n;
    vector<int> dx = {-1,1,0,0};
    vector<int> dy = {0,0,-1,1};
    int dfs(vector<vector<int>>& grid, int i, int j, int id){
        if(i<0 || i>=n || j<0 || j>=n || grid[i][j]!=1){
            return 0;
        }
        grid[i][j] = id;
        int size = 1;
        for(int d=0; d<4; d++){
            size += dfs(grid, i+dx[d], j+dy[d], id);
        }
        return size;
    }
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        unordered_map<int, int> islandsize;
        int id = 2;
        int maxisland = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    int size = dfs(grid, i, j, id);
                    islandsize[id] = size;
                    maxisland = max(maxisland, size);
                    id++;
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0){
                    unordered_set<int> uniqueneighbors;
                    for(int d=0; d<4; d++){
                        int ni = i + dx[d], nj = j + dy[d];
                        if(ni>=0 && ni<n && nj>=0 && nj<n && grid[ni][nj]>1){
                            uniqueneighbors.insert(grid[ni][nj]);
                        }
                    }
                    int total = 1;
                    for(int nid : uniqueneighbors){
                        total += islandsize[nid];
                    }
                    maxisland = max(maxisland, total);
                }
            }
        }
        return maxisland;
    }
};