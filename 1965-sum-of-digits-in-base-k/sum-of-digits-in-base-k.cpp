class Solution {
public:
    int sumBase(int n, int k) {
        int digitSum = 0;
        while(n > 0){
            digitSum = digitSum + (n % k);
            n = n / k;
            if(n < k){
                digitSum += n;
                break;
            }
        }

        return digitSum;
    }
};