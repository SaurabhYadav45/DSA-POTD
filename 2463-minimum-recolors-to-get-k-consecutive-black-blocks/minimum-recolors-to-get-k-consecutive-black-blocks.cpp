class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length();

        int minOperation = INT_MAX;
        int count = 0;

        int i=0; 
        int j=0;
        while(j < n){
            if(blocks[j] == 'W'){
                count++;
            }
            if(j-i+1 == k){
                minOperation = min(minOperation, count);
                if(blocks[i] == 'W'){
                    count--;
                }
                i++;
            }
            j++;
        }
        return minOperation;
    }
};


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