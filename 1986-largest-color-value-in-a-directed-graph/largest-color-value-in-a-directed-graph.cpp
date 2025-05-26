class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length();

        unordered_map<int, vector<int>>adj;
        vector<int>inDegree(n, 0);

        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            inDegree[v]++;
        }

        queue<int>q;

        vector<vector<int>>t(n, vector<int>(26, 0));
        for(int i=0; i<n; i++){
            if(inDegree[i] == 0){
                q.push(i);
                t[i][colors[i] - 'a'] = 1;
            }
        }

        int nodeCount = 0;
        int result = 0;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            result = max(result, t[u][colors[u] - 'a']);
            nodeCount++;

            for(auto& v : adj[u]){
                for(int i=0; i<26; i++){
                    t[v][i] = max(t[v][i], t[u][i] + (colors[v] - 'a' == i));
                }

                inDegree[v]--;

                if(inDegree[v] == 0){
                    q.push(v);
                }
            }
        }

        if(nodeCount < n){
            return -1;
        }
        return result;
    }
};