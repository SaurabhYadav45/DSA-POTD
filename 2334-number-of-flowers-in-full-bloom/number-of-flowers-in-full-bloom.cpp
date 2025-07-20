class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int>result;
        vector<int>startDay;
        vector<int>endDay;

        for(auto& flower : flowers){
            startDay.push_back(flower[0]);
            endDay.push_back(flower[1]);
        }
        sort(startDay.begin(), startDay.end());
        sort(endDay.begin(), endDay.end());

        for(int& x : people){
            int upperBound = upper_bound(startDay.begin(), startDay.end(), x) - startDay.begin();
            int lowerBound = lower_bound(endDay.begin(), endDay.end(), x) - endDay.begin();
            result.push_back(upperBound - lowerBound);
        }
        return result;
    }
};



// class Solution {
// public:
//     vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
//         vector<int>result;
//         for(int& p : people){
//             int count = 0;
//             for(auto& flower : flowers){
//                 int start = flower[0];
//                 int end = flower[1];
//                 if(p >= start && p <= end){
//                     count++;
//                 }
//             }
//             result.push_back(count);
//         }
//         return result;
//     }
// };