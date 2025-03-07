class Solution {
public:
    // bool isPrime(int num) {
    // if (num <= 1) return false;
    // for (int i = 2; i * i <= num; ++i) {
    //     if (num % i == 0) return false; 
    // }
    // return true;
    // }

    vector<bool>sieve(int upperLimit){
        vector<bool>sieve(upperLimit+1, true);
        sieve[0] = false;
        sieve[1] = false;

        for(int i=2; i*i<= upperLimit; i++){
            if(sieve[i] == true){
                for(int j = i*i; j<=upperLimit; j += i){
                    sieve[j] = false;
                }
            }
        }
        return sieve;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int>prime;
        vector<bool>isPrime = sieve(right);

        for(int i=left; i<=right; i++){
            if(isPrime[i]){
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