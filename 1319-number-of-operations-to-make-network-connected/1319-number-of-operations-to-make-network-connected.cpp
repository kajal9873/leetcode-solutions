class Solution {
public:
    vector<int> parent, rank;
    int find(int x){
        if(parent[x]!=x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    bool unite(int x, int y){
        int rootx = find(x);
        int rooty = find(y);
        if(rootx==rooty){
            return false;
        }
        if(rank[rootx]<rank[rooty]){
            parent[rootx] = rooty;
        } else if(rank[rootx]>rank[rooty]){
            parent[rooty] = rootx;
        } else{
            parent[rooty] = rootx;
            rank[rootx]++;
        }
        return true;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        if(m < n-1) return -1;
        parent.resize(n);
        rank.assign(n,0);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
        int extraedges = 0;
        for(auto& conn : connections){
            int a = conn[0], b = conn[1];
            if(!unite(a,b)){
                extraedges++;
            }
        }
        int components = 0;
        for(int i=0; i<n; i++){
            if(find(i)==i){
                components++;
            }
        }
        int needed = components-1;
        if(extraedges >= needed){
            return needed;
        }
        return -1;
    }
};