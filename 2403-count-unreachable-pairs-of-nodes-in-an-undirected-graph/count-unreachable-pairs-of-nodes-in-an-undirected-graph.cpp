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
    long long countPairs(int n, vector<vector<int>>& connections) {
        vector<int>rank(n, 1);
        vector<int>parent(n);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }

        for(auto& edge: connections){
            int parent_x = find(edge[0], parent);
            int parent_y = find(edge[1], parent);
            if(parent_x != parent_y){
                unionSet(edge[0], edge[1], parent, rank);
            }
        }

        unordered_map<int, int>mp;
        for(int i=0; i<n; i++){
            int parent_i = find(i, parent);
            mp[parent_i]++;
        }

        long long rem = n;
        long long result = 0;
        for(auto& it: mp){
            int size = it.second;
            result += (long long)(size*(rem - size));
            rem -= size;
        }
        return result;
    }
};


//     ****************** Using DSU *******************

// class Solution {
// public:
//     void dfs(unordered_map<int, vector<int>>&adjList, unordered_map<int, bool>&visited, int src, int& count){
//         visited[src] = true;
//         count++;
//         for(auto& nbr : adjList[src]){
//             if(!visited[nbr]){
//                 dfs(adjList, visited, nbr, count);
//             }
//         }
//      }
//     long long countPairs(int n, vector<vector<int>>& connections) {
//         unordered_map<int, vector<int>>adjList;
//         unordered_map<int, bool>visited;

//         for(int i=0; i<connections.size(); i++){
//             vector<int>edge = connections[i];
//             adjList[edge[0]].push_back(edge[1]);
//             adjList[edge[1]].push_back(edge[0]);
//         }

//         vector<int>nodeCounts;
//         for(int i=0; i<n; i++){
//             if(!visited[i]){
//                 int count = 0;
//                 dfs(adjList, visited, i, count);
//                 nodeCounts.push_back(count);
//             }
//         }
        
//         // long long result = 0;
//         // for(int i=0; i<nodeCounts.size(); i++){
//         //     for(int j=i+1; j<nodeCounts.size(); j++){
//         //         result += (long long)nodeCounts[i]*nodeCounts[j];
//         //     }
//         // }
//         int total = 0;
//         long long res = 0;
//         for(int i = 0;i<nodeCounts.size();i++){
//             res+=(long)((long)nodeCounts[i]*(long)(n-total-nodeCounts[i]));
//             total+=nodeCounts[i];
//         }
//         return res;
//     }
// };