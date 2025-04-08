class Solution {
public:
    
    bool checkDuplicate(vector<int>& nums, int i){
        vector<bool>arr(101, false);
        for(int j=i; j<nums.size(); j++){
            if(arr[nums[j]]){
                return true;
            }
            else{
                arr[nums[j]] = true;
            }
        }
        return false;
    }
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int operation = 0;
        int i=0;
        while(i < n){
            if(checkDuplicate(nums, i)){
                operation++;
            }
            else{
               return operation ;
            }
            i += 3;
        }
        return operation;
    }
};