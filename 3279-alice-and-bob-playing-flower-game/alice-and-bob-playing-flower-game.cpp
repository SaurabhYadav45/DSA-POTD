class Solution {
public:
    long long flowerGame(int n, int m) {
        if(n == 1 && m == 1) return 0;

        if(m % 2 == 0){
            return (long long)n * (m/2);
        }
        else if(n % 2 == 0){
            return (long long)m * (n/2);
        }
        else{
            return ((long long)((n+1)/2) * (m/2)) + ((long long)((m+1)/2) * (n/2));
        }
    }
};


// class Solution {
// public:
//     long long flowerGame(int n, int m) {
//         int count = 0;
//         for(int i=1; i<=n; i++){
//             for(int j=1; j<=m; j++){
//                 if((i+j) % 2 != 0) count++;
//             }
//         }
//         return count;
//     }
// };