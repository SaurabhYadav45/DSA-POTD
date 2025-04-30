class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int single_sum = 0;
        int double_sum = 0;
        for(int& num: nums){
            int digitCount = floor(log10(num))+1;
            if(digitCount % 2 == 1){
                single_sum += num;
            }
            else{
                double_sum += num;
            }
        }
        if(single_sum == double_sum){
            return false;
        }
        return true;
    }
};