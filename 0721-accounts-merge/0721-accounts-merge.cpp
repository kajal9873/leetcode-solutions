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
        } else if(rank[rootx]>rank[rooty]){
            parent[rooty] = rootx;
        } else{
            parent[rooty] = rootx;
            rank[rootx]++;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent.resize(n);
        rank.assign(n,0);
        for(int i=0; i<n; i++) parent[i] = i;
        unordered_map<string, int> emailtoaccount;
        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                string email = accounts[i][j];
                if(emailtoaccount.find(email)!=emailtoaccount.end()){
                    unite(i, emailtoaccount[email]);
                }else{
                    emailtoaccount[email] = i;
                }
            }
        }
        unordered_map<int, set<string>> roottoemails;
        for(auto& entry : emailtoaccount){
            string email = entry.first;
            int owner = entry.second;
            int root = find(owner);
            roottoemails[root].insert(email);
        }
        vector<vector<string>> result;
        for(auto& entry : roottoemails){
            int root = entry.first;
            vector<string> mergedaccount;
            mergedaccount.push_back(accounts[root][0]);
            for(const string& email : entry.second){
                mergedaccount.push_back(email);
            }
            result.push_back(mergedaccount);
        }
        return result;
    }
};