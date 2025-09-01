class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int maxSum = 0;
        int lSum = 0, rSum = 0;

        for(int i = 0; i<k; i++){
            lSum += cardPoints[i];
        }
        maxSum = max(maxSum, (lSum + rSum));

        int j = n-1;
        for(int i=k-1; i>=0; i--){
            lSum -= cardPoints[i];
            rSum += cardPoints[j];
            maxSum = max(maxSum, (lSum + rSum));
            j--;
        }
        return maxSum;
    }
};


//   **************** better **********

// class Solution {
// public:
//     int maxScore(vector<int>& cardPoints, int k) {
//         int n = cardPoints.size();
//         int maxSum = 0;
//         vector<int>pSum(n+1, 0);
//         vector<int>sSum(n+1, 0);
//         // pSum[0] = cardPoints[0];
        
//         for(int i=0; i<n; i++){
//             pSum[i+1] = pSum[i] + cardPoints[i];
//         }

//         // sSum[n-1] = cardPoints[n-1];
//         for(int i=n-1; i>=0; i--){
//             sSum[i] = sSum[i+1] + cardPoints[i];
//         }

//         for(int i=0; i<=k; i++){
//             int sum = pSum[i] + sSum[n-k+i];
//             maxSum = max(maxSum, sum);
//         }
//         return maxSum;
//     }
// };

//     ***************** Brute Force : TLE ****************

// class Solution {
// public:
//     int maxScore(vector<int>& cardPoints, int k) {
//         int n = cardPoints.size();
//         int maxSum = 0;
//         for(int i=0; i<=k; i++){
//             int sum = 0;
//             for(int j=0; j<i; j++){
//                 sum += cardPoints[j];
//             }

//             for(int j=n-k+i; j < n; j++){
//                 sum += cardPoints[j];
//             }

//             maxSum = max(maxSum, sum);
//         }
//         return maxSum;
//     }
// };