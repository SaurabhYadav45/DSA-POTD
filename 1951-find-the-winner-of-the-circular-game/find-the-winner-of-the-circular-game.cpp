//              ***************** Using Recursion ****************

// class Solution {
// public:
//     int findWinnerIndex(int n, int k){
//         if(n == 1) return 0;

//         int idx = findWinnerIndex(n-1, k);
//         idx = (idx + k) % n;
//         return idx;
//     }
//     int findTheWinner(int n, int k) {
//         int idx = findWinnerIndex(n, k);
//         return idx+1;
//         }
//     };



//              ***************** Using Queue ****************

// class Solution {
// public:
//     int findTheWinner(int n, int k) {
//         queue<int>q;
//         for(int i=1; i<=n; i++){
//             q.push(i);
//         }

//         while(q.size() != 1){
//             for(int i=1; i<k; i++){
//                 q.push(q.front());
//                 q.pop();
//             }
//             q.pop();
//         }
//         return q.front();
//     }
// };


//              ***************** Using Array ****************

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>nums;
        for(int i=1; i<=n; i++){
            nums.push_back(i);
        }

        int idx=0;
        while(nums.size() > 1){
            idx = (idx + k -1) % nums.size();
            nums.erase(nums.begin()+idx);
        }
        return nums[0];
    }
};