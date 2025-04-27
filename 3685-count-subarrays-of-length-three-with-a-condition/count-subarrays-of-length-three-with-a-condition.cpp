class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for(int i=0; i<=n-3; i++){
            vector<int>temp;
            for(int j=i; j<i+3; j++){
                temp.push_back(nums[j]);
                if(temp.size() == 3){
                    int first = temp[0];
                    int second = temp[1];
                    int third = temp[2];

                    if(first + third  == ((double)second/2))count++;
                }
            }
        }
        return count;
    }
};