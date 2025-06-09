class Solution {
public:
    int countFun(long curr, long next, int n){
        int countNum = 0;
        while(curr <= n){
            countNum += (next- curr);

            curr *= 10;
            next *= 10;
            next = min(next, long(n+1));
        }
        return countNum;
    }
    int findKthNumber(int n, int k) {
        long curr = 1;
        k -= 1; // Since we starting from first element itself

        while(k > 0){
            int count = countFun(curr, curr+1, n);
            if(count <= k){
                curr += 1;
                k -= count;
            }
            else{
                curr *= 10;
                k -= 1;
            }
        }
        return curr;
    }
};