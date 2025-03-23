class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
    long long res = 0;
    for (const auto &q : queries) {
        long long l = q[0], r = q[1], sum = 0, p = 0;
        for (long long p4 = 1; p4 <= r; p4 *= 4) { 
            int pl = max(l, p4), pr = min(r, p4 * 4 - 1);
            sum += max(0LL, ++p * (pr - pl + 1));
        }
        res += (sum + 1) / 2;
    }
    return res;
}
};
// class Solution {
// public:
//     int countOp(priority_queue<int>&pq){
//         int count = 0;
//         while(!pq.empty()){
//             int a = pq.top();
//             pq.pop();

//             if (pq.empty()) {
//                 if (a > 0) pq.push(a / 4); 
//                 count++;
//                 break;
//             }
//             int b = pq.top();
//             pq.pop();

//             if(a == 0 && b == 0){
//                 break;
//             }

//             if(a != 0){
//                  pq.push(floor(a/4));
//             }
//             if(b != 0){
//                  pq.push(floor(b/4));
//             }
//             count++;
//         }
//         return count;
//     }
//     long long minOperations(vector<vector<int>>& queries) {
//         int n = queries.size();
//         long long result = 0;

//         for(int i=0; i<n; i++){
//             priority_queue<int>pq;
//             int l = queries[i][0];
//             int r = queries[i][1];
//             for(int num=l; num<=r; num++){
//                 pq.push(num);
//             }
//             int op = countOp(pq);
//             result += op;
//         }
//         return result;
//     }
// };