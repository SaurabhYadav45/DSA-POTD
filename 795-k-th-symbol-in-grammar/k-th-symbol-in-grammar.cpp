class Solution {
public:
    int kthGrammar(int n, int k) {
        // Base case
        if(k == 1) return 0;

        long long length = 1;
        long long newK;
        while(true){
            length *= 2;
            if(length >= k){
                newK = k - length/2;
                break;
            }
        }

        int num = kthGrammar(n, newK);
        if(num == 0) return 1;
        else return 0;
    }
};