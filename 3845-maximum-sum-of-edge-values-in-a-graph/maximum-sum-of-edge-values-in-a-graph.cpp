class Solution {
public:
    bool dfs(int i, int p, vector<vector<int>>&adj, vector<bool>&visited, int&count){
        count++;
        visited[i] = true;
        bool ans = false;

        for(auto&nbr: adj[i]){
            if(nbr == p) continue;
            if(visited[nbr]){
                ans = true;
            }
            else{
                ans |= dfs(nbr, i, adj, visited, count);
            }
        }
        return ans;
    }
    long long maxScore(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);

        for(auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool>visited(n, false);
        vector<int>cycle, chain;

        for(int i=0; i<n; i++){
            if(visited[i] == true){
                continue;
            }
            int count = 0;
            if(dfs(i, -1, adj, visited, count)){
                cycle.push_back(count);
            }
            else{
                chain.push_back(count);
            }
        }

        sort(cycle.rbegin(), cycle.rend());
        sort(chain.rbegin(), chain.rend());

        long long result = 0;
        for(auto x : cycle){
            result += (long long)n*(n-1 + n-2);
            n -= 3;
            x -= 3;

            while(x){
                result += (long long)n*(n+2);
                n--;
                x--;
            }
            result += (long long)(n+1)*(n+2);
        }

        for(auto x: chain){
            if(x == 1)break;
            if(x == 2){
                result += (long long)n*(n-1);
                n -= 2;
                continue;
            }

            result += (long long)n*((n-1)+(n-2));
            n -= 3;
            x -= 3;
            while(x){
                result += (long long)n*(n+2);
                n--;
                x--;
            }
        }
        return result;
    }
};