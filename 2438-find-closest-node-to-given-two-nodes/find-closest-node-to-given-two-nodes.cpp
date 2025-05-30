// class Solution {
// public:
//     vector<int>bfs(vector<int>&edges, int node){
//         int n = edges.size();
//         queue<pair<int, int>>q;
//         q.push({node, 0});
//         vector<int>distances(n, INT_MAX);
//         distances[node] = 0;

//         while(!q.empty()){
//             int curr = q.front().first;
//             int dist = q.front().second;
//             q.pop();

//             int nbr = edges[curr];
//             dist++;
//             if(nbr != -1 && dist < distances[nbr]){
//                 distances[nbr] = dist;
//                 q.push({nbr, dist});
//             }
//         }
//         return distances;
//     }
//     int closestMeetingNode(vector<int>& edges, int node1, int node2) {
//         vector<int>distances1 = bfs(edges, node1);
//         vector<int>distances2 = bfs(edges, node2);

//         int result = INT_MAX-1;
//         int idx = -1;

//         for(int i=0; i<distances1.size(); i++){
//             distances1[i] = max(distances1[i], distances2[i]);
//             if(result < distances1[i]){
//                 result = min(result, distances1[i]);
//                 idx = i;
//             }
//         }
//         return idx;
//     }
// };




class Solution {
public:
    int n;
    
    void bfs(vector<int>& edges, int startNode, vector<int>& dist_node) {
        queue<int> que;
        que.push(startNode);
        dist_node[startNode] = 0;
        vector<bool> visited(n, false);
        visited[startNode] = true;
        
        while(!que.empty()) {
            int u = que.front();
            que.pop();
            
            int v = edges[u];
            
            if(v != -1 && !visited[v]) {
                visited[v] = true;
                dist_node[v] = 1 + dist_node[u];
                que.push(v);
            }
        }
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        n = edges.size();
        
        vector<int> dist1(n, INT_MAX);
        vector<int> dist2(n, INT_MAX);
        
        bfs(edges, node1, dist1);
        bfs(edges, node2, dist2);
        
        
        int minDistNode    = -1;
        int minDistTillNow = INT_MAX;
        for (int i = 0; i < n; i++) {
            
            int maxD = max(dist1[i], dist2[i]);
            
            if (minDistTillNow > maxD) {
                minDistNode = i;
                minDistTillNow = maxD;
            }
        }

        return minDistNode;
        
    }
};