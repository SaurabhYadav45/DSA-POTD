#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> res, count;
    vector<vector<int>> adj;
    int N;

    void dfs1(int u, int parent) {
        for (int v : adj[u]) {
            if (v == parent) continue;
            dfs1(v, u);
            count[u] += count[v];
            res[u] += res[v] + count[v];
        }
    }

    void dfs2(int u, int parent) {
        for (int v : adj[u]) {
            if (v == parent) continue;
            res[v] = res[u] - count[v] + (N - count[v]);
            dfs2(v, u);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        N = n;
        adj.assign(n, {});
        res.assign(n, 0);
        count.assign(n, 1); // each node counts as itself

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs1(0, -1); // Step 1: compute res[0] and subtree sizes
        dfs2(0, -1); // Step 2: re-root and compute for all nodes

        return res;
    }
};




// class Solution {
// public:
//     void dfs(int src, unordered_map<int, vector<int>>&adj, vector<bool>&visited, int currLevel, int& sum){
//         visited[src] = true;
//         sum += currLevel;

//         for(auto& nbr: adj[src]){
//             if(!visited[nbr]){
//                 dfs(nbr, adj, visited, currLevel+1, sum);
//             }
//         }
//     }
//     vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
//         unordered_map<int, vector<int>>adj;
//         for(auto& edge: edges){
//             int u = edge[0];
//             int v = edge[1];
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }

//         vector<int>result;

//         for(int i=0; i<n; i++){
//             vector<bool>visited(n, false);
//             int sum = 0;
//             dfs(i, adj, visited, 0, sum);
//             result.push_back(sum);
//         }
//         return result;
//     }
// };




// class Solution {
// public:
//     int N;
//     long long bfs(int src, unordered_map<int, vector<int>>&adj){
//         int sum = 0;
//         queue<pair<int, int>>q;
//         q.push({src, 0});
//         vector<bool>visited(N, false);
//         visited[src] = true;

//         while(!q.empty()){
//             int size = q.size();
//             while(size--){
//                 int node = q.front().first;
//                 int d = q.front().second;
//                 q.pop();

//                 sum += d;
                
//                 for(auto& nbr: adj[node]){
//                     if(!visited[nbr]){
//                         q.push({nbr, d+1});
//                         visited[nbr] = true;
//                     }
//                 }
//             }
//         }
//         return sum;
//     }
//     vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
//         N = n;
//         unordered_map<int, vector<int>>adj;
//         for(auto& edge: edges){
//             int u = edge[0];
//             int v = edge[1];
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }

//         vector<int>result;

//         for(int i=0; i<n; i++){
//             // vector<bool>visited(n, false);
//             int sum = bfs(i, adj);
//             result.push_back(sum);
//         }
//         return result;
//     }
// };