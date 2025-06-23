class Solution {
public:
    const int MOD = 1e9+7;
    long long calculatePower(long long a, long long b){
        // Base case
        if(b == 0) return 1;
        
        long long half = calculatePower(a, b/2);
        long long result = (half*half)%MOD;

        if(b%2 == 1){
            result = (result*a) % MOD;
        }
        return result;
    }
    long long countGoodNumbers(long long n) {
        long long evenCount = (n+1)/2;
        long long oddCount = n/2;
        long long result = (calculatePower(5, evenCount)*calculatePower(4, oddCount)) % MOD;
        return result;
    }
};





// class Solution {
// public:
//     const int MOD = 1e9+7;
//     bool checkGoodNumbers(long long num){
//         string s = to_string(num);
//         for(int i=0; i<s.length(); i++){
//             int n = s[i]+'0';
//             if(i%2 != n%2){
//                 return false;
//             }
//         }
//         return true;
//     }
//     int countGoodNumbers(long long n) {
//         long long start = pow(10, n-1);
//         long long end = pow(10, n)-1;

//         long long count = 0;
//         for(long long num = start; num<=end; num++){
//             if(checkGoodNumbers(num)){
//                 count++;
//             }
//         }
//         return count%MOD;
//     }
// };