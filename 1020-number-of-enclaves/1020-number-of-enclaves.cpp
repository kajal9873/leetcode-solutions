class Solution {
public:
    int m, n;
    void dfs(vector<vector<int>>& grid, int x, int y){
        if(x<0 || x>=m || y<0 || y>=n || grid[x][y]==0) return;
        grid[x][y]=0;
        dfs(grid, x-1, y);
        dfs(grid, x+1, y);
        dfs(grid, x, y-1);
        dfs(grid, x, y+1);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for(int i=0; i<m; i++){
            if(grid[i][0]==1) dfs(grid,i,0);
            if(grid[i][n-1]==1) dfs(grid,i,n-1);
        }
        for(int j=0; j<n; j++){
            if(grid[0][j]==1) dfs(grid,0,j);
            if(grid[m-1][j]==1) dfs(grid,m-1,j);
        }
        int count=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1) count++;
            }
        }
        return count;
    }
};