class Solution {
public:
    int dfs(int u, int parent, unordered_map<int, vector<int>>&adj, string&s, int& result){
        vector<int>lengthCount;

        for(auto& child: adj[u]){
            if(child == parent) continue;
            int child_length = dfs(child, u, adj, s, result);

            if(s[u] != s[child]){
                lengthCount.push_back(child_length);
            }
        }

        sort(lengthCount.rbegin(), lengthCount.rend());
        int longest = (lengthCount.size() > 0 ? lengthCount[0] : 0);
        int secondLongest = (lengthCount.size() > 1 ? lengthCount[1] : 0);

        int case1 = longest+secondLongest + 1; // when longest path is lied in child itself
        int case2 = longest + 1; // when one child has longest path
        int case3 = 1; // when all child has same adjacent character

        result = max({result, case1, case2, case3});
        return max(case2, case3);
    }
    int longestPath(vector<int>& parent, string s) {
        unordered_map<int, vector<int>>adj;
        for(int i=1; i<parent.size(); i++){
            int p = parent[i];
            adj[p].push_back(i);
            adj[i].push_back(p);
        }

        int result = 0;
        dfs(0, -1, adj, s, result);

        return result;
    }
};