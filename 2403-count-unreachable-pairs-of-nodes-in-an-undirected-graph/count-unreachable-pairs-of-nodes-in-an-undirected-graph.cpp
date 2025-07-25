class Solution {
public:
    void dfs(unordered_map<int, vector<int>>&adjList, unordered_map<int, bool>&visited, int src, int& count){
        visited[src] = true;
        count++;
        for(auto& nbr : adjList[src]){
            if(!visited[nbr]){
                dfs(adjList, visited, nbr, count);
            }
        }
     }
    long long countPairs(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<int>>adjList;
        unordered_map<int, bool>visited;

        for(int i=0; i<connections.size(); i++){
            vector<int>edge = connections[i];
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        vector<int>nodeCounts;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                int count = 0;
                dfs(adjList, visited, i, count);
                nodeCounts.push_back(count);
            }
        }
        
        // long long result = 0;
        // for(int i=0; i<nodeCounts.size(); i++){
        //     for(int j=i+1; j<nodeCounts.size(); j++){
        //         result += (long long)nodeCounts[i]*nodeCounts[j];
        //     }
        // }
        int total = 0;
        long long res = 0;
        for(int i = 0;i<nodeCounts.size();i++){
            res+=(long)((long)nodeCounts[i]*(long)(n-total-nodeCounts[i]));
            total+=nodeCounts[i];
        }
        return res;
    }
};