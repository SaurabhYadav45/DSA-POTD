class Solution {
public:
    int intersect(const unordered_set<int>& a_set, const unordered_set<int>& b_set, int k){
        int count =0;

        for(int num : a_set){
            if(b_set.find(num) != b_set.end()){
                count++;
                if(count >= k) return count;
            }
        }
        return count;
    }
    void dfs(unordered_map<int, vector<int>>&adj, vector<bool>&visited, int i){
        visited[i] = true;

        for(auto& nbr: adj[i]){
            if(!visited[nbr]){
                dfs(adj, visited, nbr);
            }
        }
    }
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();

        unordered_map<int, vector<int>>adj;
        vector<unordered_set<int>> propertySets(n);
        for (int i = 0; i < n; i++) {
            for (int num : properties[i]) {
                propertySets[i].insert(num);
            }
        }

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(intersect(propertySets[i], propertySets[j], k) >= k){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool>visited(n, false);
        int count = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(adj, visited, i);
                count++;
            }
        }
        return count;
    }
};