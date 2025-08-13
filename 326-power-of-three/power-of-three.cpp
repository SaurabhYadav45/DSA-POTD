class Solution {
public:
    bool solve(long n, long result){
        if(n == result) return true;
        if(n < result) return false;
        return solve(n, result*3);
    }
    bool isPowerOfThree(long n) {
        long result = 1;
        return solve(n, result);
    }
};