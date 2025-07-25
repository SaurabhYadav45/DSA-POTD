class Solution {
public:
    int find(int i, vector<int>&parent){
        if(parent[i] == i) return i;
        return parent[i] = find(parent[i], parent);
    }

    void unionSet(int x, int y, vector<int>&parent, vector<int>&rank){
        int parent_x = find(x, parent);
        int parent_y = find(y, parent);

        if(parent_x == parent_y) return ;
        else if(rank[parent_x] > rank[parent_y]){
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n-1) return -1;

        vector<int>rank(n, 1);
        vector<int>parent(n);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }

        int component = n;

        for(auto& edge: connections){
            int parent_x = find(edge[0], parent);
            int parent_y = find(edge[1], parent);
            if(parent_x != parent_y){
                unionSet(edge[0], edge[1], parent, rank);
                component--;
            }
        }

        return component-1;
    }
};



//        **************** Using Graph ************************

// class Solution {
// public:
//     void dfs(unordered_map<int, vector<int>>&adjList, unordered_map<int, bool>&visited, int src){
//         visited[src] = true;
//         for(auto& nbr : adjList[src]){
//             if(!visited[nbr]){
//                 dfs(adjList, visited, nbr);
//             }
//         }
//      }
//     int makeConnected(int n, vector<vector<int>>& connections) {
//         if (connections.size() < n-1) return -1;

//         unordered_map<int, vector<int>>adjList;
//         unordered_map<int, bool>visited;

//         for(int i=0; i<connections.size(); i++){
//             vector<int>edge = connections[i];
//             adjList[edge[0]].push_back(edge[1]);
//             adjList[edge[1]].push_back(edge[0]);
//         }

//         int count = 0;
//         for(int i=0; i<n; i++){
//             if(!visited[i]){
//                 dfs(adjList, visited, i);
//                 count++;
//             }
//         }
//         return count -1;
//     }
// };