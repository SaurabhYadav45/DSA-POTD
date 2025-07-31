class Solution {
public:
    typedef pair<long long, int> P;
    const int MOD = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>>adj;
        for(auto& edge: roads){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        priority_queue<P, vector<P>, greater<P>>pq;
        pq.push({0, 0});

        vector<long long>distance(n, LLONG_MAX);
        vector<long long>pathCount(n, 0);
        distance[0] = 0;
        pathCount[0] = 1;

        while(!pq.empty()){
            int u = pq.top().second;
            long long d = pq.top().first;
            pq.pop();

            for(auto& nbr: adj[u]){
                int v = nbr.first;
                long long dist = nbr.second;
                if(d + dist < distance[v]){
                    distance[v] = d + dist;
                    pathCount[v] = pathCount[u];
                    pq.push({d+dist, v});
                }
                else if(d + dist == distance[v]){
                    pathCount[v] = (pathCount[v] + pathCount[u])%MOD;
                }
            }
        }
        return pathCount[n-1];
    }
};