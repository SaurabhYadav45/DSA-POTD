//          **************** Using Krushkal Algo ********************

class Solution {
public:
    int find(int i, vector<int>&parent){
        if(i == parent[i]) return i;
        return parent[i] = find(parent[i], parent);
    }
    
    void unionSet(int x, int y, vector<int>&parent, vector<int>&rank){
        int parent_x = find(x, parent);
        int parent_y = find(y, parent);
        
        if(parent_x == parent_y) return;
        
        if(rank[parent_x] > rank[parent_y]){
            parent[parent_y] = parent_x;
        }
        else if(rank[parent_y] > rank[parent_x]){
            parent[parent_x] = parent_y;
        }
        else{
            parent[parent_y] = parent_x;
            rank[parent_x]++;
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();

        vector<int>parent(V);
        vector<int>rank(V, 1);
        
        for(int i=0; i<V; i++){
            parent[i] = i;
        }

        vector<vector<int>>edges;
        for(int i=0; i<V; i++){
            for(int j=i+1; j<V; j++){
                int x1 = points[i][0];
                int y1 = points[i][1];
                
                int x2 = points[j][0];
                int y2 = points[j][1];

                int wt = abs(x2-x1) + abs(y2-y1);
                edges.push_back({i, j, wt});
            }
        }

        auto lambda = [&](vector<int>&vec1, vector<int>&vec2){
            return vec1[2] < vec2[2];
        };

        sort(edges.begin(), edges.end(), lambda);

        int minCost = 0;

        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            int parent_u = find(u, parent);
            int parent_v = find(v, parent);

            if(parent_u != parent_v){
                unionSet(u, v, parent, rank);
                minCost += wt;
            }
        }
        return minCost;
    }
};








// class Solution {
// public:
//     typedef pair<int, int> P;
//     int minCost(vector<vector<P>>&adj){
//         vector<bool>visited(adj.size(), false);
//         priority_queue<P, vector<P>, greater<P>>pq;
//         pq.push({0, 0});
//         int sum = 0;

//         while(!pq.empty()){
//             auto p = pq.top();
//             pq.pop();

//             int wt = p.first;
//             int node = p.second;

//             if(visited[node] == true){
//                 continue;
//             }

//             visited[node] = true;
//             sum += wt;

//             for(auto& temp : adj[node]){
//                 int nbr = temp.first;
//                 int nbr_wt = temp.second;

//                 if(visited[nbr] == false){
//                     pq.push({nbr_wt, nbr});
//                 }
//             }
//         }
//         return sum;
//     }
//     int minCostConnectPoints(vector<vector<int>>& points) {
//         // Create adjacency liost
//         int n = points.size();
//         vector<vector<P>> adj(n);
        
//         for(int i=0; i<n; i++){
//             for(int j=i+1; j<n; j++){
//                 int x1 = points[i][0];
//                 int y1 = points[i][1];
//                 int x2 = points[j][0];
//                 int y2 = points[j][1];

//                 int dist = abs(x1-x2) + abs(y1-y2);
//                 adj[i].push_back({j, dist});
//                 adj[j].push_back({i, dist});
//             }
//         }
//         return(minCost(adj));
//     }
// };