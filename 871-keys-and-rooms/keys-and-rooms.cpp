class Solution {
public:
    void dfs(int src, vector<vector<int>>& rooms, vector<bool>&visited){
        visited[src] = true;

        for(auto& nbr: rooms[src]){
            if(!visited[nbr]){
                dfs(nbr, rooms, visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>visited(n, false);
        dfs(0,rooms, visited);

        for(int i=0; i<n; i++){
            if(visited[i] == false) 
                return false;
        }
        return true;
    }
};