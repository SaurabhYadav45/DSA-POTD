class Solution {
public:
    typedef long long ll;
    ll calculateSum(ll count, ll val){
        return val*count - (count*(count+1))/2;
    }
    int maxValue(int n, int index, int maxSum) {
        ll low = 1;
        ll high = maxSum;
        ll mid;
        int result = 0;

        while(low <= high){
            mid = low + (high-low)/2;
            ll left_count = min((ll)index, mid-1);
            ll left_sum = calculateSum(left_count, mid);
            left_sum += max(0LL, index - mid+1);

            ll right_count = min((ll)n-index-1, mid-1);
            ll right_sum = calculateSum(right_count, mid);
            right_sum += max(0LL, n-index-1 - mid+1);

            if(right_sum + left_sum + mid <= maxSum){
                result = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return result;
    }
};




// class Solution {
// public:
//     typedef long long ll;
//     ll calculateSum(ll count, ll val){
//         return val*count - (count*(count+1))/2;
//     }
//     int maxValue(int n, int index, int maxSum) {
//         for(ll maxIdxValue = maxSum; maxIdxValue >= 1; maxIdxValue--){
//             ll left_count = min((ll)index, maxIdxValue-1);
//             ll left_sum = calculateSum(left_count, maxIdxValue);
//             left_sum += max(0LL, index - maxIdxValue+1);

//             ll right_count = min((ll)n-index-1, maxIdxValue-1);
//             ll right_sum = calculateSum(right_count, maxIdxValue);
//             right_sum += max(0LL, n-index-1 - maxIdxValue+1);

//             if(left_sum + right_sum + maxIdxValue <= maxSum){
//                 return maxIdxValue;
//             }
//         }
//         return -1;
//     }
// };



//             **************** Brute Force *******************

// class Solution {
// public:
//     int maxValue(int n, int index, int maxSum) {
//         for(int maxIdxValue = maxSum; maxIdxValue >= 1; maxIdxValue--){
//             long long sum  = maxIdxValue;
//             int maxValue = maxIdxValue-1;
//             for(int i=index-1; i>=0; i--){
//                 if(maxValue >= 1){
//                     sum += maxValue;
//                     maxValue--;
//                 }
//                 else{
//                     sum = sum + 1;
//                 }

//                 if(sum > maxSum){
//                     break;
//                 }
//             }

//             // calculate right sum
//             maxValue = maxIdxValue-1;
//             for(int i = index+1; i < n; i++){
//                 if(maxValue >= 1){
//                     sum += maxValue;
//                     maxValue--;
//                 }
//                 else{
//                     sum = sum + 1;
//                 }

//                 if(sum > maxSum){
//                     break;
//                 }
//             }

//             if(sum <= maxSum){
//                 return maxIdxValue;
//             }
//         }
//         return 1;
//     }
// };