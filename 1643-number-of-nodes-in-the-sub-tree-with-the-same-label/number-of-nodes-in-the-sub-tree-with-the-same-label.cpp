class Solution {
public:
    vector<int> dfs(int i, int parent, unordered_map<int, vector<int>>&adj, string& labels, vector<int>&result){
        vector<int>curr_count(26, 0);
        char ch = labels[i];
        curr_count[ch - 'a']++;

        for(auto& child: adj[i]){
            if(child == parent) continue;
            vector<int>childCount = dfs(child, i, adj, labels, result);
            
            for(int i=0; i<26; i++){
                curr_count[i] += childCount[i];
            }
        }

        result[i] = curr_count[ch-'a'];
        return curr_count;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        unordered_map<int, vector<int>>adj;
        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>result(n, 0);
        dfs(0, -1, adj, labels, result);

        return result;
    }
};