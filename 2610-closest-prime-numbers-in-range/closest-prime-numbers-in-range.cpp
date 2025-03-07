class Solution {
public:
    bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false; 
    }
    return true;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int>prime;

        for(int i=left; i<=right; i++){
            if(isPrime(i)){
                prime.push_back(i);
            }
        }

        int num1 = -1;
        int num2 = -1;
        int result = INT_MAX;

        for(int i = prime.size()-1; i>=1; i--){
            if(prime[i] - prime[i-1] <= result){
                num1 = prime[i-1];
                num2 = prime[i];
                result = prime[i]-prime[i-1];
            }
        }
        return {num1, num2};
    }
};