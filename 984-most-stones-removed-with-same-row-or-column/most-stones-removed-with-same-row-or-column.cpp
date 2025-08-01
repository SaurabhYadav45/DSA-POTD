class Solution {
public:
    int find(int i, vector<int>&parent){
        if( parent[i] == i) return i;
        return parent[i] = find(parent[i], parent);
    }

    void unionSet(int x, int y, vector<int>&parent, vector<int>&rank){
        int parent_x = find(x, parent);
        int parent_y = find(y, parent);

        if(parent_x == parent_y){
            return;
        }

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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int>parent(n);
        vector<int>rank(n, 1);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int parent_x = find(i, parent);
                int parent_y = find(j, parent);
                if(parent_x == parent_y) continue;
                // If parents are not same, add them in single group if same row or column
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    unionSet(i, j, parent, rank);
                }
            }
        }

        int count = 0;

        for(int i=0; i<n; i++){
            if(i == parent[i])count++;
        }

        return n - count;
    }
};



//       **************** Using DFS *************************

// class Solution {
// public:
//     void dfs(int src, vector<vector<int>>& stones, vector<bool>&visited){
//         visited[src] = true;

//         for(int i=0; i<stones.size(); i++){
//             int row = stones[src][0];
//             int col = stones[src][1];
//             if(!visited[i] && (stones[i][0] == row || stones[i][1] == stones[src][1])){
//                 dfs(i, stones, visited);
//             }
//         }
//     }
//     int removeStones(vector<vector<int>>& stones) {
//         int n = stones.size();
//         vector<bool>visited(n, false);
//         int count = 0;

//         for(int i=0; i<n; i++){
//             if(!visited[i]){
//                 dfs(i, stones, visited);
//                 count++;
//             }
//         }
//         return n - count;
//     }
// };