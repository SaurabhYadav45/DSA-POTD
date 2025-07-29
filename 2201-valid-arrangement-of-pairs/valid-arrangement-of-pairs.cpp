class Solution{
    public:
    vector<vector < int>> validArrangement(vector<vector < int>> &pairs){
        unordered_map<int, vector<int>>adj;
        unordered_map<int, int>inDegree, outDegree;
        for(auto& pair: pairs){
            int u = pair[0];
            int v = pair[1];
            adj[u].push_back(v);
            inDegree[v]++;
            outDegree[u]++;
        }

        int startNode = pairs[0][0];
        for(auto& it: adj){
            int node = it.first;
            if(outDegree[node] - inDegree[node] == 1){
                startNode = node;
                break;
            }
        }

        stack<int>st;
        vector<int>eulerPath;
        st.push(startNode);

        while(!st.empty()){
            int curr = st.top();
            if(!adj[curr].empty()){
                int nbr = adj[curr].back();
                adj[curr].pop_back();
                st.push(nbr);
            }
            else{
                eulerPath.push_back(curr);
                st.pop();
            }
        }

        reverse(eulerPath.begin(), eulerPath.end());
        vector<vector<int>>result;
        for(int i=1; i<eulerPath.size(); i++){
            result.push_back({eulerPath[i-1], eulerPath[i]});
        }
        return result;
    }
};