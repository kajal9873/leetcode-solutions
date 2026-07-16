class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        if(n==1) return 1;
        vector<pair<int, int>> directions = {
            {-1,-1}, {-1,0}, {-1,1},
            {0,-1},        {0,1},
            {1,-1}, {1,0}, {1,1}
        };
        vector<vector<bool>> visited(n, vector<bool>(n,false));
        queue<pair<int, int>> q;
        q.push({0,0});
        visited[0][0] = true;
        int pathlength = 1;
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                auto[row,col] = q.front();
                q.pop();
                if(row==n-1 && col==n-1) return pathlength;
                for(auto& [dr,dc] : directions){
                    int newrow = row + dr;
                    int newcol = col + dc;
                    if(newrow>=0 && newrow<n && newcol>=0 && newcol<n &&
                    grid[newrow][newcol]==0 && !visited[newrow][newcol]){
                        visited[newrow][newcol] = true;
                        q.push({newrow,newcol});
                    }
                }
            }
            pathlength++;
        }
        return -1;
    }
};