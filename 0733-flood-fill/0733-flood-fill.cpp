class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    void dfs(vector<vector<int>>& image, int r, int c, int oldcolour, int newcolour){
        int m = image.size();
        int n = image[0].size();
        if(r<0 || r>=m || c<0 || c>=n) return;
        if(image[r][c]!=oldcolour) return;
        image[r][c]=newcolour;
        for(int i=0; i<4; i++) dfs(image, r+dx[i], c+dy[i], oldcolour, newcolour);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldcolour = image[sr][sc];
        if(oldcolour==color) return image;
        dfs(image, sr, sc, oldcolour, color);
        return image;
    }
};