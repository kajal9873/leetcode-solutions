class Solution {
public:
    int rows, cols;
    void dfs(vector<vector<char>>& grid, int r, int c){
        if(r<0 || r>=rows || c<0 || c>=cols || grid[r][c]=='0') return;
        grid[r][c] = '0';
        dfs(grid, r+1, c);
        dfs(grid, r-1, c);
        dfs(grid, r, c+1);
        dfs(grid, r, c-1);
    } 
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        rows = grid.size();
        cols = grid[0].size();
        int islandcount = 0;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j]=='1'){
                    islandcount++;
                    dfs(grid, i, j);
                }
            }
        }
        return islandcount;
    }
};