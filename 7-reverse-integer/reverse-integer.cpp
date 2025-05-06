class Solution {
public:
    int reverse(long long x) {
        int sign = x > 0 ? 1 : -1;
        long long result = 0;
        long long n = abs(x);

        while(n != 0){
            int rem = n % 10;
            result = result*10 + rem;
            n /= 10;
        }

        return result > 2147483647 ? 0 : sign*result;
    }
};