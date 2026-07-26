class Solution {
public:
    vector<int> parent, rank;
    int find(int x){
        if(parent[x]!=x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void unite(int x, int y){
        int rootx = find(x);
        int rooty = find(y);
        if(rootx==rooty) return;
        if(rank[rootx]<rank[rooty]){
            parent[rootx] = rooty;
        }else if(rank[rootx]>rank[rooty]){ 
            parent[rooty] = rootx;
        }else{
            parent[rooty] = rootx;
            rank[rootx]++;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        const int offset = 10001;
        int maxnodes = 20002;
        parent.resize(maxnodes);
        rank.assign(maxnodes, 0);
        for(int i=0; i<maxnodes; i++){
            parent[i] = i;
        }
        for(auto& stone : stones){
            int x = stone[0];
            int y = stone[1] + offset;
            unite(x,y);
        }
        unordered_set<int> uniqueroots;
        for(auto& stone : stones){
            int x = stone[0];
            int root = find(x);
            uniqueroots.insert(root);
        }
        int components = uniqueroots.size();
        return n - components;
    }
};