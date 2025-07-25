class Solution {
public:
    void dfs(unordered_map<int, vector<int>>&adjList, unordered_map<int, bool>&visited, int src){
        visited[src] = true;
        for(auto& nbr : adjList[src]){
            if(!visited[nbr]){
                dfs(adjList, visited, nbr);
            }
        }
     }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n-1) return -1;

        unordered_map<int, vector<int>>adjList;
        unordered_map<int, bool>visited;

        for(int i=0; i<connections.size(); i++){
            vector<int>edge = connections[i];
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        int count = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(adjList, visited, i);
                count++;
            }
        }
        return count -1;
    }
};