class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int>mp;

        int i=0, j=0;
        int result = 0;

        while(j < n){
            int fruit = fruits[j];
            mp[fruit]++;
            while(mp.size() > 2){
                mp[fruits[i]]--;
                if(mp[fruits[i]] == 0){
                    mp.erase(fruits[i]);
                }
                i++;
            }

            result = max(result, j-i+1);
            j++;
        }
        return result;
    }
};