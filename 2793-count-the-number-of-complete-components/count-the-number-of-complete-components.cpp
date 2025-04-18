class Solution {
public:
    void bfs(int i, unordered_map<int, vector<int>>&adj, vector<bool>&visited, int& v, int& e){
        queue<int>q;
        q.push(i);
        visited[i] = true;

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            v++;
            e += adj[curr].size();

            for(int& nbr : adj[curr]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>>adj;

        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool>visited(n, false);
        int count = 0;
        
        for(int i=0; i<n; i++){
            if(visited[i] == true) continue;

            int v = 0;
            int e = 0;
            bfs(i, adj, visited, v, e);

            if((v*(v-1)/2) == e/2){
                count++;
            }
        }
        return count;
    }
};


// class Solution {
// public:
//     void dfs(int i, unordered_map<int, vector<int>>&adj, vector<bool>&visited, int& v, int& e){
//         visited[i] = true;
//         v++;
//         e += adj[i].size();

//         for(auto& nbr : adj[i]){
//             if(!visited[nbr]){
//                 dfs(nbr, adj, visited, v, e);
//             }
//         }
//     }
//     int countCompleteComponents(int n, vector<vector<int>>& edges) {
//         unordered_map<int, vector<int>>adj;

//         for(auto& edge : edges){
//             int u = edge[0];
//             int v = edge[1];
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }

//         vector<bool>visited(n, false);
//         int count = 0;
        
//         for(int i=0; i<n; i++){
//             if(visited[i] == true) continue;

//             int v = 0;
//             int e = 0;
//             dfs(i, adj, visited, v, e);

//             if((v*(v-1)/2) == e/2){
//                 count++;
//             }
//         }
//         return count;
//     }
// };