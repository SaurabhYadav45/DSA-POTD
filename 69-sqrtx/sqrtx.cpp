// class Solution {
// public:
//     int mySqrt(int x) {
//         int s = 0;
//         int e = x;
//         long long int mid = s + (e-s)/2;
//         int ans = -1;
//         while(s<=e){
//             if(mid*mid == x)
//             return mid;

//             else if(mid*mid < x){
//                 ans = mid;
//                 s = mid + 1;
//             }
//             else {
//                 e = mid-1;
//             }
//             mid = s + (e-s)/2;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        int r = x;
        int result=0;
        while(l <= r){
            long long mid = l + (r-l)/2;
            if(mid * mid == x){
                return mid;
            }
            if(mid * mid > x){
                r = mid-1;
            }
            else{
                // mid*mid < x
                result = mid;
                l = mid+1;
            }
        }
        return result;
    }
};