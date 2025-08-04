class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int>mp;
        int i=0, j=0;
        
        int result = 0;
        int count = 0;

        while(j < n){
            int fruit = fruits[j];
            mp[fruit]++;
            while(mp.size() > 2 && i < j){
                mp[fruits[i]]--;
                count--;
                if(mp[fruits[i]] == 0){
                    mp.erase(fruits[i]);
                }
                i++;
            }
            count++;

            result = max(result, count);
            j++;
        }
        return result;
    }
};