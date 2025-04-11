class Solution {
public:
    int isSymmetric(int num){
        int countDigit = (int)(log10(num)+1);
        if(countDigit % 2 == 1)return false;
        
        int n = countDigit/2;
        int sum1 = 0;
        while(n--){
            sum1 += num%10;
            num /= 10;
        }
        int sum2 = 0;
        n = countDigit/2;
        while(n--){
            sum2 += num%10;
            num /= 10;
        }
        if(sum1 == sum2){
            return true;
        }
        return false;
    }
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for(int i=low; i<=high; i++){
            if(isSymmetric(i)){
                count++;
            }
        }
        return count;
    }
};