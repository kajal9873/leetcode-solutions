class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const long long MOD = 1e9+7;
        vector<vector<pair<int,long long>>> graph(n);
        for(auto& r : roads){
            int u=r[0], v=r[1];
            long long w = r[2];
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        }
        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n,0);
        dist[0]=0;
        ways[0]=1;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto [d,u] = pq.top();
            pq.pop();
            if(d>dist[u]) continue;
            for(auto& [v,w] : graph[u]){
                long long newdist = dist[u] + w;
                if(newdist<dist[v]){
                    dist[v] = newdist;
                    ways[v] = ways[u];
                    pq.push({dist[v],v});
                }
                else if(newdist==dist[v]){
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }
        return (int)(ways[n-1]%MOD);
    }
};