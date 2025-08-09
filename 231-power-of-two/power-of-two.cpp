// class Solution {
// public:
//     bool solve(long n, long result){
//         if(n == result) return true;
//         if(n < result) return false;
//         return solve(n, result*2);
//     }
//     bool isPowerOfTwo(long n) {
//         long result = 1;
//         return solve(n, result);
//     }
// };

// Method-2 : Bit Manuipulation
class Solution {
public:
    
    bool isPowerOfTwo(long n) {
        if(n <= 0) return 0;
        long count = 0;
        while(n != 0){
            int lastbit = (n & 1);
            if(lastbit == 1) count++;

            n = n>>1;
        }
        if(count == 1) return true;

        return false;
    }
};