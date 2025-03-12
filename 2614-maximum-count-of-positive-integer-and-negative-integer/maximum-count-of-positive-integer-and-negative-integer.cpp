class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int posCount = nums.end() - upper_bound(nums.begin(), nums.end(), 0);
        int negCount = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        return max(posCount, negCount);
    }
};


//                  ********* BRute Force **********
//                  ********* T.C = O (n)

// class Solution {
// public:
//     int maximumCount(vector<int>& nums) {
//         int posCount = 0;
//         int negCount = 0;

//         for(int& num : nums){
//             if(num > 0) posCount++;
//             else if(num < 0) negCount++;
//         }
//         return max(posCount, negCount);
//     }
// };