class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        vector<string>result;

        unordered_set<string>st(supplies.begin(), supplies.end());

        vector<bool>cooked(n, false);

        int count = n;

        while(count--){
            for(int i=0; i<n; i++){

                if(cooked[i] == true){
                    continue;
                }
                bool isPossible = true;
                for(int j=0; j<ingredients[i].size(); j++){
                    if(!st.count(ingredients[i][j])){
                        isPossible = false;
                        break;
                    }
                }

                if(isPossible){
                    result.push_back(recipes[i]);
                    st.insert(recipes[i]);
                    cooked[i] = true;
                }
            }
        }
        return result;
    }
};