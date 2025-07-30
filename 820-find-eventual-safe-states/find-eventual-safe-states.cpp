class Solution {
public:
    bool dfs(int src, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& inRecursion) {
        visited[src] = true;
        inRecursion[src] = true;

        for(auto& nbr: adj[src]){
            if(visited[nbr] && inRecursion[nbr]) return false;
            if(!visited[nbr] && dfs(nbr, adj, visited, inRecursion) == false){
                return false;
            }
        }

        inRecursion[src] = false;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        
        vector<bool>visited(V, false);
        vector<bool>inRecursion(V, false);

        for(int i=0; i<V; i++){
            if(!visited[i]){
                dfs(i, graph, visited, inRecursion);
            }
        }

        vector<int>result;
        for(int i=0; i<V; i++){
            bool b = inRecursion[i];
            if(b == false)result.push_back(i);
        }

        return result;
    }
};
