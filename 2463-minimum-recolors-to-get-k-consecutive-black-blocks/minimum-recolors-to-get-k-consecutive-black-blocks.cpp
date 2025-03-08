//              *************Using Queue *********
//                          T.C = O (n)
//                          S.C = O (k) : Queue

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length();

        queue<char>q;

        int whiteCount = 0;
        while(q.size() < k){
            char curr = blocks[q.size()];
            if(curr == 'W'){
                whiteCount++;
            }
            q.push(curr);
        }

        int minOperation = whiteCount;

        for(int i=k; i<n; i++){
            if(q.front() == 'W')whiteCount--;
            q.pop();

            if(blocks[i] == 'W') whiteCount++;
            q.push(blocks[i]);

            minOperation = min(minOperation, whiteCount);
        }
        return minOperation;
    }
};


//              *************Using Sliding Window *********
//                          T.C = O (n)
//                          S.C = O (1)


// class Solution {
// public:
//     int minimumRecolors(string blocks, int k) {
//         int n = blocks.length();

//         int minOperation = INT_MAX;
//         int count = 0;

//         int i=0; 
//         int j=0;
//         while(j < n){
//             if(blocks[j] == 'W'){
//                 count++;
//             }
//             if(j-i+1 == k){
//                 minOperation = min(minOperation, count);
//                 if(blocks[i] == 'W'){
//                     count--;
//                 }
//                 i++;
//             }
//             j++;
//         }
//         return minOperation;
//     }
// };



//              *************Brute Force *********
//                          T.C = O (n*k)
//                          S.C = O (1) : Queue

// class Solution {
// public:
//     int minimumRecolors(string blocks, int k) {
//         int n = blocks.length();

//         int minOperation = INT_MAX;

//         for(int i=0; i<=n-k; i++){
//             int whiteCount = 0;
//             for(int j=i; j<i+k; j++){
//                 if(blocks[j] == 'W'){
//                     whiteCount++;
//                 }
//             }
//             minOperation = min(minOperation, whiteCount);
//         }
//         return minOperation;
//     }
// };