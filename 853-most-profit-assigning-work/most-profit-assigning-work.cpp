class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>>pairs;
        for(int i=0; i<profit.size(); i++){
            pairs.push_back({difficulty[i], profit[i]});
        }
        sort(pairs.begin(), pairs.end());
        for(int i=1; i<pairs.size(); i++){
            pairs[i].second = max(pairs[i].second, pairs[i-1].second);
        }

        int result = 0;
        for(int& w : worker){
            int maxProfit = 0;
            for(auto& pair: pairs){
                int diff = pair.first;
                int profit = pair.second;
                if(w >= diff){
                    maxProfit = max(maxProfit, profit);
                }
                else{
                    break;
                }
            }
            result += maxProfit;
        }
        return result;
    }
};



// class Solution {
// public:
    
//     int binarySearch(vector<pair<int, int>>job, int worker){
//         int start = 0;
//         int end = job.size()-1;
//         int maxProfit = 0;

//         while(start <= end){
//             int mid  = (start + end)/2;
//             if(job[mid].first <= worker){
//                 maxProfit = max(job[mid].second, maxProfit);
//                 start = mid+1;
//             }
//             else{
//                 end = mid-1;
//             }
//         }
//         return maxProfit;
//     }
//     int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
//         vector<pair<int, int>>job(difficulty.size());
//         for(int i=0; i<difficulty.size(); i++){
//             job.push_back({difficulty[i], profit[i]});
//         }

//         sort(job.begin(), job.end());
//         sort(worker.begin(), worker.end());
        
//         int ans  =0;
//         int maxProfit = 0;
//         int j=0;
//         for(int i=0; i<worker.size(); i++){
//             while( j< job.size() && job[j].first <= worker[i]){
//                 maxProfit = max(maxProfit, job[j].second);
//                 j++;
//             }
//             ans += maxProfit;
//         }
//         return ans;

//         // Binary Search 
//         // int ans =0;
//         // for(int i=0; i<worker.size(); i++){
//         //     int maxProfit = binarySearch(job, worker[i]);
//         //     ans += maxProfit;
//         // }
//         // return ans;
//     }
// };