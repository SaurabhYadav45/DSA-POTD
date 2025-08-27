class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = INT_MIN;
        for(int i=1; i<prices.size(); i++){
            if(prices[i] > minPrice){
                maxProfit = max(maxProfit, prices[i]-minPrice);
            }
            minPrice = min(minPrice, prices[i]);
        } 
        if(maxProfit == INT_MIN) return 0;
        return maxProfit;
    }
};


// class Solution {
// public:

//     void maxProfitFinder(vector<int>& prices, int i, int &minPrice, int &maxProfit){
//         // Base Case
//         if(i == prices.size()) return;

//         if(prices[i]< minPrice) minPrice  = prices[i];
//         int todaysProfit = prices[i] - minPrice;
//         if(todaysProfit > maxProfit) maxProfit = todaysProfit;

//         maxProfitFinder(prices, i+1, minPrice, maxProfit);
//     }

//     int maxProfit(vector<int>& prices) {
//         int minPrice = INT_MAX;
//         int maxProfit = INT_MIN;
//         maxProfitFinder(prices, 0, minPrice, maxProfit);

//         return maxProfit;
//     }
// };


// BRUTE FORCE

// class Solution {
// public:

//     int maxProfit(vector<int>& prices) {
//         int minPrice = INT_MAX;
//         int maxProfit = INT_MIN;
//         for(int i=0; i<prices.size()-1; i++){
//             for(int j=i+1; j<prices.size(); j++){
//                 minPrice = prices[i];
//                 if(prices[j] > prices[i]){
//                     maxProfit = max(maxProfit, (prices[j]-prices[i]));
//                 }
//             }
//         }
//         if(maxProfit == INT_MIN) return 0;

//         return maxProfit;
//     }
// };