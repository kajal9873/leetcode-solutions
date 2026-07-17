class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> effort(rows, vector<int>(cols, INT_MAX));
        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq;
        vector<pair<int,int>> directions = {{-1,0},{0,1},{0,-1},{1,0}};
        effort[0][0] = 0;
        pq.push({0,0,0});
        while(!pq.empty()){
            auto[curreffort, row, col] = pq.top();
            pq.pop();
            if(row==rows-1 && col==cols-1) return curreffort;
            if(curreffort>effort[row][col]) continue;
            for(auto& [dr,dc] : directions){
                int newrow = dr + row;
                int newcol = dc + col;
                if(newrow>=0 && newrow<rows && newcol>=0 && newcol<cols){
                    int diff = abs(heights[newrow][newcol]-heights[row][col]);
                    int neweffort = max(curreffort, diff);
                    if(neweffort<effort[newrow][newcol]){
                        effort[newrow][newcol] = neweffort;
                        pq.push({neweffort, newrow, newcol});
                    }
                }
            }
        }
        return effort[rows-1][cols-1];
    }
};