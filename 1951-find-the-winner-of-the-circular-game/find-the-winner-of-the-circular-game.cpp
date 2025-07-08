class Solution {
public:
    int findWinnerIndex(int n, int k){
        if(n == 1) return 0;

        int idx = findWinnerIndex(n-1, k);
        idx = (idx + k) % n;
        return idx;
    }
    int findTheWinner(int n, int k) {
        int idx = findWinnerIndex(n, k);
        return idx+1;
        }
    };








// class Solution {
// public:
//     int findWinnerIndex(int n, int k){
//         // base case
//         if(n == 0){
//             return 0; // index
//         }

//         int idx = findWinnerIndex(n-1, k);
//         idx = (idx+k)%n;  // To find the original index in the original array

//         return idx;
//     }

//     int findTheWinner(int n, int k) {

//         int idx = findWinnerIndex(n, k);
//         return idx+1;

//     //     //  Method -2 : Using Queue

// //             queue<int>q;
// //             for(int i=1; i<=n; i++)
// //                 q.push(i);
            
// //             while(q.size() > 1){
// //                 for(int i = 1; i<k; i++){
// //                     auto player = q.front();
// //                     q.pop();
// //                     q.push(player);
// //                 }
// //                 q.pop();
// //             }
// //             return q.front();
//         }
//     };
