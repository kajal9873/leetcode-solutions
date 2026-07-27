class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n,false));
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        vector<int> dx = {-1,1,0,0};
        vector<int> dy = {0,0,-1,1};
        pq.push({grid[0][0],0,0});
        while(!pq.empty()){
            auto [t,x,y] = pq.top();
            pq.pop();
            if(visited[x][y]) continue;
            visited[x][y] = true;
            if(x==n-1 && y==n-1) return t;
            for(int d=0; d<4; d++){
                int nx = x + dx[d], ny = y + dy[d];
                if(nx<0 || nx>=n || ny<0 || ny>=n || visited[nx][ny]) continue;
                int newt = max(t, grid[nx][ny]);
                pq.push({newt, nx, ny});
            }
        }
        return -1;
    }
};