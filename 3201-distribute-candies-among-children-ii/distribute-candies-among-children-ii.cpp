// class Solution {
// public:
//     long long distributeCandies(int n, int limit) {
//         long long ans = 0;
//         for (int i = 0; i <= min(limit, n); i++) {
//             if (n - i > 2 * limit) {
//                 continue;
//             }
//             ans += min(n - i, limit) - max(0, n - i - limit) + 1;
//         }
//         return ans;
//     }
// };



class Solution {
public:
    long long cal(int x) {
        if (x < 0) {
            return 0;
        }
        return (long)x * (x - 1) / 2;
    }

    long long distributeCandies(int n, int limit) {
        return cal(n + 2) - 3 * cal(n - limit + 1) +
               3 * cal(n - (limit + 1) * 2 + 2) - cal(n - 3 * (limit + 1) + 2);
    }
};