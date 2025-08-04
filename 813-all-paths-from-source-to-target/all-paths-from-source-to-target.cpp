class Solution {
public:
    int n;
    void dfs(int src, vector<vector<int>>& graph, vector<int>&curr, vector<vector<int>>&result){
        curr.push_back(src);

        if(src == n-1){
            result.push_back(curr);
        }

        for(auto& nbr: graph[src]){
            dfs(nbr, graph, curr, result);
        }

        curr.pop_back(); // Backtrack
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        vector<vector<int>>result;
        vector<int>curr;
        dfs(0, graph, curr, result);
        return result;
    }
};