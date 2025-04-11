// class Solution {
// public:
//     int isSymmetric(int num){
//         int countDigit = (int)(log10(num)+1);
//         if(countDigit % 2 == 1)return false;
        
//         int n = countDigit/2;
//         int sum1 = 0;
//         while(n--){
//             sum1 += num%10;
//             num /= 10;
//         }
//         int sum2 = 0;
//         n = countDigit/2;
//         while(n--){
//             sum2 += num%10;
//             num /= 10;
//         }
//         if(sum1 == sum2){
//             return true;
//         }
//         return false;
//     }
//     int countSymmetricIntegers(int low, int high) {
//         int count = 0;
//         for(int i=low; i<=high; i++){
//             if(isSymmetric(i)){
//                 count++;
//             }
//         }
//         return count;
//     }
// };


class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for(int num=low; num<=high; num++){
            if(num >= 10 && num <= 99 && num%11 == 0){
                count++;
            }
            else if(num>= 1000 && num<= 9999){
                int first = (num / 1000);
                int second = (num / 100)%10;
                int third = (num / 10)%10;
                int fourth = (num%10);

                if(first + second == third + fourth){
                    count++;
                }
            }
        }
        return count;
    }
};