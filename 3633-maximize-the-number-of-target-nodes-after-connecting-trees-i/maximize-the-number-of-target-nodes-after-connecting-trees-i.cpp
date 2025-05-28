// class Solution {
// public:
//     int bfs(int i, unordered_map<int, vector<int>>&adj, int k, int size){
//         queue<int>q;
//         q.push(i);
//         int x = k;
//         int count = 1;
//         if(x < 0) return 0;
//         if(x == 0) return 1;
//         vector<int>visited(size, false);
//         visited[i] = true;

//         while(!q.empty()){
//             if(x == 0) return count;
//             int top = q.front();
//             q.pop();
//             bool check = false;
//             for(auto& nbr: adj[top]){
//                 if(!visited[nbr]){
//                     count++;
//                     q.push(nbr);
//                     visited[nbr] = true;
//                     check = true;
//                 }
//             }
//             if(check){
//                 x--;
//             }
//         }
//         return count;
//     }
//     vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
//         int m = edges1.size();
//         int n = edges2.size();
//         vector<int>result(m+1, 0);
//         vector<int>result2(n+1, 0);
        

//         unordered_map<int, vector<int>>adj;

//         for(auto& edge : edges1){
//             int u = edge[0];
//             int v = edge[1];
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }

//         unordered_map<int, vector<int>>adj2;

//         for(auto& edge : edges2){
//             int u = edge[0];
//             int v = edge[1];
//             adj2[u].push_back(v);
//             adj2[v].push_back(u);
//         }

//         // calculate for graph2

//         for(int i=0; i<=n; i++){
//             result2[i] = bfs(i, adj2, k-1, n+1);
//         }

//         int maxValue = *max_element(result2.begin(), result2.end());

//         // calculate for graph1

//         for(int i=0; i<=m; i++){
//             result[i] = bfs(i, adj, k, m+1);
//         }

//         for(int i=0; i<=m; i++){
//             result[i] += maxValue;
//         }
//         return result;
//     }
// };



class Solution {
public:
    int dfs(int node, int parent, const vector<vector<int>>& children, int k) {
        if (k < 0) {
            return 0;
        }
        int res = 1;
        for (int child : children[node]) {
            if (child == parent) {
                continue;
            }
            res += dfs(child, node, children, k - 1);
        }
        return res;
    }

    vector<int> build(const vector<vector<int>>& edges, int k) {
        int n = edges.size() + 1;
        vector<vector<int>> children(n);
        for (const auto& edge : edges) {
            children[edge[0]].push_back(edge[1]);
            children[edge[1]].push_back(edge[0]);
        }
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = dfs(i, -1, children, k);
        }
        return res;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<int> count1 = build(edges1, k);
        vector<int> count2 = build(edges2, k - 1);
        int maxCount2 = *max_element(count2.begin(), count2.end());
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = count1[i] + maxCount2;
        }
        return res;
    }
};