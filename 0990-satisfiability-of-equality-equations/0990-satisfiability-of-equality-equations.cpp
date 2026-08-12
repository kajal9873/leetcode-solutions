class Solution {
public:
    vector<int> parent;
    int find(int x){
        if(parent[x]!=x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void unite(int x, int y){
        int rootx = find(x);
        int rooty = find(y);
        if(rootx != rooty){
            parent[rootx] = rooty;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        for(int i=0; i<26; i++){
            parent[i] = i;
        }
        for(string& eq : equations){
            char x = eq[0];
            char op1 = eq[1];
            char y = eq[3];
            if(op1 == '='){
                unite(x-'a',y-'a');
            }
        }
        for(string& eq : equations){
            char x = eq[0];
            char op1 = eq[1];
            char y = eq[3];
            if(op1 == '!'){
                if(find(x-'a')==find(y-'a')){
                    return false;
                }
            }
        }
        return true;
    }
};