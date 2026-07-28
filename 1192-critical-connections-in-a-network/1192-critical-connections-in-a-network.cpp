class Solution {
public:
    vector<vector<int>> adj;
    vector<int> disc, low;
    vector<bool> visited;
    vector<vector<int>> bridges;
    int timer = 0;
    void dfs(int node, int parent){
        visited[node] = true;
        disc[node] = low[node] = timer++;
        for(int neighbor : adj[node]){
            if(neighbor==parent) continue;
            if(!visited[neighbor]){
                dfs(neighbor, node);
                low[node] = min(low[node],low[neighbor]);
                if(low[neighbor]>disc[node]){
                    bridges.push_back({node,neighbor});
                }
            }else{
                low[node] = min(low[node],disc[neighbor]);
            }
        }
    } 
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        adj.assign(n, vector<int>());
        disc.assign(n,-1);
        low.assign(n,-1);
        visited.assign(n,false);
        for(auto& conn : connections){
            adj[conn[0]].push_back(conn[1]);
            adj[conn[1]].push_back(conn[0]);
        }
        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(i,-1);
            }
        }
        return bridges;
    }
};