class Solution {
public:
     
    int minimumPairRemoval(vector<int>& nums) {
        int minOp = 0;
        while(true){
            int n = nums.size();
            bool sorted = true;
            // Check if array is sorted
            for(int i=0; i<n-1; i++){
                if(nums[i] > nums[i+1]){
                    sorted = false;
                    break;
                }
            }
            if(sorted){
                break;
            }
            // find minSum and index
            int minSum = INT_MAX;
            int index = 0;
            for(int i = 0; i<n-1; i++){
                if(nums[i] + nums[i+1] < minSum){
                    minSum = nums[i]+nums[i+1];
                    index = i;
                }
            }

            // delete index+1 element
            nums.erase(nums.begin()+index+1);
            // replace the element at index with the minSum
            nums[index] = minSum;
            minOp++;
        }
        return minOp;
    }
};