class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {

        int count = 0;
        long long curr = 0;
        long long maxVal = 0;
        long long minVal = 0;

        for(int diff : differences){
            curr +=  diff;
            maxVal = max(maxVal, curr);
            minVal = min(minVal, curr);
        }
        if((upper-maxVal) - (lower-minVal) + 1 <= 0){
            return  0;
        }
        count = (upper-maxVal) - (lower-minVal) + 1;
        return count;
    }
};





// class Solution {
// public:
//     int numberOfArrays(vector<int>& differences, int lower, int upper) {
//         int n = differences.size();

//         int count = 0;

//         for(int i=lower; i<=upper; i++){
//             bool flag = true;
//             int prev = i;
//             int curr = 0;
//             for(int j=0; j<n; j++){
//                 curr = prev + differences[j];
//                 if(curr < lower || curr > upper){
//                     flag = false;
//                     break;
//                 }
//                 prev = curr;
//             }
//             if(flag == false){
//                 continue;
//             }
//             count++;
//         }
//         return count;
//     }
// };



// class Solution {
// public:
//     int numberOfArrays(vector<int>& differences, int lower, int upper) {
//         int n = differences.size();

//         int count = 0;

//         for(int i=lower; i<=upper; i++){
//             vector<int>nums(n+1, 0);
//             nums[0] = i;
//             bool flag = true;
//             for(int j=1; j<nums.size(); j++){
//                 nums[j] = differences[j-1] + nums[j-1];
//                 if(nums[j] < lower || nums[j] > upper){
//                     flag = false;
//                     break;
//                 }
//             }
//             if(flag == false){
//                 continue;
//             }
//             count++;
//         }
//         return count;
//     }
// };