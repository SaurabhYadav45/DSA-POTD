
//       ******************** Using Kahn's Algo *****************

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();

        // Reverse the existing graph OR Create a new Graph with reverse edge
        vector<vector<int>>reverseGraph(V);
        vector<int>inDegree(V, 0);
        for(int u=0; u<V; u++){
            for(auto& v: graph[u]){
                reverseGraph[v].push_back(u);
                inDegree[u]++;
            }
        }

        queue<int>q;
        for(int i=0; i<V; i++){
            if(inDegree[i] == 0)q.push(i);
        }

        vector<int>result;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            result.push_back(node);

            for(auto& nbr: reverseGraph[node]){
                inDegree[nbr]--;
                if(inDegree[nbr] == 0)q.push(nbr);
            }
        }
        
        sort(result.begin(), result.end());
        return result;
    }
};


//      ****************** Using DFS ************************

// class Solution {
// public:
//     bool dfs(int src, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& inRecursion) {
//         visited[src] = true;
//         inRecursion[src] = true;

//         for(auto& nbr: adj[src]){
//             if(visited[nbr] && inRecursion[nbr]) return false;
//             if(!visited[nbr] && dfs(nbr, adj, visited, inRecursion) == false){
//                 return false;
//             }
//         }

//         inRecursion[src] = false;
//         return true;
//     }

//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//         int V = graph.size();
        
//         vector<bool>visited(V, false);
//         vector<bool>inRecursion(V, false);

//         for(int i=0; i<V; i++){
//             if(!visited[i]){
//                 dfs(i, graph, visited, inRecursion);
//             }
//         }

//         vector<int>result;
//         for(int i=0; i<V; i++){
//             bool b = inRecursion[i];
//             if(b == false)result.push_back(i);
//         }

//         return result;
//     }
// };
