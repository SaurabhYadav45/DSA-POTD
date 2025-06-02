class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        vector<int>count(n, 1);
        vector<int>count2(n, 1);

        for(int i=1; i<n; i++){
            if(ratings[i] > ratings[i-1]){
                count[i] = max(count[i], count[i-1]+1);
            }
        }

        int result = 0;

        for(int i=n-2; i>=0; i--){
            if(ratings[i] > ratings[i+1]){
                count2[i] = max(count2[i], count2[i+1]+1);
            }
        }

        for(int i=0; i<n; i++){
            result += max(count[i], count2[i]);
        }
        return result;
    }
};