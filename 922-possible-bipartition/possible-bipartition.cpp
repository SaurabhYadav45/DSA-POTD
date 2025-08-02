class Solution {
public:
    bool dfs(int i, unordered_map<int, vector<int>>&adj, vector<int>&color, int currColor){
        color[i] = currColor;

        for(auto& nbr: adj[i]){
            if(color[i] == color[nbr]) return false;

            if(color[nbr] == -1){
                if(dfs(nbr, adj, color, 1-currColor) == false){
                    return false;
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>>adj;
        for(auto& edge: dislikes){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>color(n+1, -1);
        for(int i=1; i<=n; i++){
            if(color[i] == -1){
                int currColor = 1;
                if(dfs(i, adj, color, currColor) == false){
                    return false;
                }
            }
        }
        return true;
    }
};


//            ****************** Using BFS *******************

// class Solution {
// public:
//     bool bfs(int i, unordered_map<int, vector<int>>&adj, vector<int>&color){
//         queue<int>q;
//         q.push(i);
//         color[i] = 1;

//         while(!q.empty()){
//             int node = q.front();
//             q.pop();

//             for(auto& nbr: adj[node]){
//                 if(color[node] == color[nbr]){
//                     return false;
//                 }

//                 if(color[nbr] == -1){
//                     q.push(nbr);
//                     color[nbr] = 1 - color[node];
//                 }
//             }
//         }
//         return true;
//     }
//     bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
//         unordered_map<int, vector<int>>adj;
//         for(auto& edge: dislikes){
//             int u = edge[0];
//             int v = edge[1];
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }

//         vector<int>color(n+1, -1);
//         for(int i=1; i<=n; i++){
//             if(color[i] == -1){
//                 if(bfs(i, adj, color) == false){
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
// };



// class Solution {
// public:
//     int find(int i, vector<int>&parent){
//         if(i == parent[i]) return i;
//         return parent[i] = find(parent[i], parent);
//     }

//     void unionSet(int x, int y, vector<int>&parent, vector<int>&rank){
//         int parent_x = find(x, parent);
//         int parent_y = find(y, parent);

//         if(parent_x == parent_y){
//             return;
//         }

//         if(rank[parent_x] > rank[parent_y]){
//             parent[parent_y] = parent_x;
//         }
//         else if(rank[parent_y] > rank[parent_x]){
//             parent[parent_x] = parent_y;
//         }
//         else{
//             parent[parent_y] = parent_x;
//             rank[parent_x]++;
//         }
//     }
//     bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
//         vector<int>rank(n+1, 1);
//         vector<int>parnet(n+1);
//         for(int i=0; i<=n; i++){
//             parent[i] = i;
//         }

//         for(auto& dislike: dislikes){
//             int x = dislike[0];
//             int y = dislike[1];

//             int parent_x = find(x, parent);
//             int parent_y = find(y, parent);

//             if(parent_x )
//         }
//     }
// };