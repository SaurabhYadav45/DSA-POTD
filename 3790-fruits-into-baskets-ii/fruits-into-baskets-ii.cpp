class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int m = fruits.size();
        int n = baskets.size();

        vector<bool>allocated(n, false);

        for(int i=0; i < m; i++){
            for(int j=0; j<n; j++){
                if(fruits[i] <= baskets[j] && allocated[j] == false){
                    allocated[j] = true;
                    break;
                }
            }
        }

        int count = 0;
        for(bool num : allocated){
            if(num == false) count++;
        }
        return count;
    }
};