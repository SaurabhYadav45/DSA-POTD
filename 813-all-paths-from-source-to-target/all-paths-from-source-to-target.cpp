class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>result;
        queue<vector<int>>q;

        q.push({0});

        while(!q.empty()){
            vector<int>curr = q.front();
            int lastNode = curr.back();
            q.pop();

            if(lastNode == n-1){
                result.push_back(curr);
            }

            for(auto& nbr: graph[lastNode]){
                curr.push_back(nbr);
                q.push(curr);
                curr.pop_back();
            }
        }
        return result;
    }
};


// class Solution {
// public:
//     int n;
//     void dfs(int src, vector<vector<int>>& graph, vector<int>&curr, vector<vector<int>>&result){
//         curr.push_back(src);

//         if(src == n-1){
//             result.push_back(curr);
//         }

//         for(auto& nbr: graph[src]){
//             dfs(nbr, graph, curr, result);
//         }

//         curr.pop_back(); // Backtrack
//     }
//     vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
//         n = graph.size();
//         vector<vector<int>>result;
//         vector<int>curr;
//         dfs(0, graph, curr, result);
//         return result;
//     }
// };