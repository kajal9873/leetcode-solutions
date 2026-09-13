class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int,int>> A, B;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(img1[i][j]==1) A.push_back({i,j});
                if(img2[i][j]==1) B.push_back({i,j});
            }
        }
        if(A.empty() || B.empty()) return 0;
        unordered_map<int,int> freq;
        int best = 0;
        int shift = n;
        for(auto &a : A){
            for(auto &b : B){
                int dx = b.first - a.first;
                int dy = b.second - a.second;
                int key = (dx+shift) * 100 + (dy+shift);
                int c = ++freq[key];
                best = max(best,c);
            }
        }
        return best;
    }
};