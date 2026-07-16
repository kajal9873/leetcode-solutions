class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,0);
        vector<int> result;
        for(int i=0; i<n; i++){
            if(issafe(i, graph, color)){
                result.push_back(i);
            }
        }
        return result;
    }
private:
    bool issafe(int node, vector<vector<int>>& graph, vector<int>& color){
        if(color[node]==2) return true;
        if(color[node]==1) return false;
        color[node] = 1;
        for(int neighbour : graph[node]){
            if(!issafe(neighbour, graph, color)){
                return false;
            }
        }
        color[node] = 2;
        return true;
    }
};