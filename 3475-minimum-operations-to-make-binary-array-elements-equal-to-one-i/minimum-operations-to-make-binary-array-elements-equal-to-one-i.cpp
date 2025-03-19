class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count = 0;
        for (int i = 2; i < nums.size(); i++) {
            // only looking forward to the last element
            if (nums[i - 2] == 0) {
                count++;
                // flip i-2 and i-1 and i
                nums[i - 2] ^= 1;
                nums[i - 1] ^= 1;
                nums[i] ^= 1;
            }
        }
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum == nums.size()) return count;
        return -1;
    }
};





//     class Solution {
// public:
//     int minOperations(vector<int>& nums) {
//         deque<int> flipQueue;
//         int count = 0;

//         for (int i = 0; i < nums.size(); i++) {
//             while (!flipQueue.empty() && i > flipQueue.front() + 2) {
//                 flipQueue.pop_front();
//             }

//             if ((nums[i] + flipQueue.size()) % 2 == 0) {
//                 if (i + 2 >= nums.size()) {
//                     return -1;
//                 }
//                 count++;
//                 flipQueue.push_back(i);
//             }
//         }

//         return count;
//     }
// };