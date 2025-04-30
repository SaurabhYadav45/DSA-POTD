class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int result = 0;
        for(int& num : nums){
            int count = 0;
            while(num > 0){
                count ++;
                num /= 10;
            }
            if(count%2 == 0){
                result++;
            }
        }
        return result;
    }
};