class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        vector<string>result;

        unordered_set<string>st(supplies.begin(), supplies.end());

        queue<int>q;

        unordered_map<string, vector<int>>adj;
        vector<int>inDegree(n, 0);

        for(int i=0; i<n; i++){
            for(string& ing : ingredients[i]){
                if(!st.count(ing)){
                    adj[ing].push_back(i);
                    inDegree[i]++;
                }
            }
        }

        for(int i=0; i<n; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int i = q.front();
            q.pop();

            string recipe = recipes[i];
            result.push_back(recipe);

            for(int& idx: adj[recipe]){
                inDegree[idx]--;
                if(inDegree[idx] == 0){
                    q.push(idx);
                }
            }
        }
        return result;
    }
};


//             ************ Brute Force *************

// class Solution {
// public:
//     vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
//         int n = recipes.size();
//         vector<string>result;

//         unordered_set<string>st(supplies.begin(), supplies.end());

//         vector<bool>cooked(n, false);

//         int count = n;

//         while(count--){
//             for(int i=0; i<n; i++){

//                 if(cooked[i] == true){
//                     continue;
//                 }
//                 bool isPossible = true;
//                 for(int j=0; j<ingredients[i].size(); j++){
//                     if(!st.count(ingredients[i][j])){
//                         isPossible = false;
//                         break;
//                     }
//                 }

//                 if(isPossible){
//                     result.push_back(recipes[i]);
//                     st.insert(recipes[i]);
//                     cooked[i] = true;
//                 }
//             }
//         }
//         return result;
//     }
// };