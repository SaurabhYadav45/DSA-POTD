class Solution {
public:
    int find(int i, vector<int>&parent){
        if(parent[i] == i) return i;
        return parent[i] = find(parent[i], parent);
    }

    void unionSet(int x, int y, vector<int>&parent, vector<int>&rank){
        int parent_x = find(x, parent);
        int parent_y = find(y, parent);

        if(parent_x == parent_y) return ;
        else if(rank[parent_x] > rank[parent_y]){
            parent[parent_y] = parent_x;
        }
        else if(rank[parent_y] > rank[parent_x]){
            parent[parent_x] = parent_y;
        }
        else{
            parent[parent_y] = parent_x;
            rank[parent_x]++;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        vector<int>rank(26, 1);
        vector<int>parent(26);
        for(int i=0; i<26; i++){
            parent[i] = i;
        }

        for(string& s: equations){
            if(s[1] == '='){
                int x = s[0]-'a';
                int y = s[3]-'a';
                unionSet(x, y, parent, rank);
            }
        }

        for(string& s: equations){
            if(s[1] == '!'){
                int x = s[0]-'a';
                int y = s[3]-'a';
                int parent_x = find(x, parent);
                int parent_y = find(y, parent);
                if(parent_x == parent_y) return false;
            }
        }
        return true;
    }
};