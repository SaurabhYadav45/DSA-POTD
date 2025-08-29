class Solution {
public:
    int t[100001][2][3];
    int solve(int i, int buy, int cap, vector<int>& prices){
        if(i >= prices.size()) return 0;
        if(cap == 0) return 0;

        if(t[i][buy][cap] != -1){
            return t[i][buy][cap];
        }

        if(buy){
            int take = -prices[i] + solve(i+1, 0, cap, prices);
            int skip = solve(i+1, 1, cap, prices);
            return t[i][buy][cap] = max(take, skip);
        }
        else{
            // sell
            int sell = prices[i] + solve(i+1, 1, cap-1, prices);
            int dont_sell = solve(i+1, 0, cap, prices);
            return t[i][buy][cap] = max(sell, dont_sell);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memset(t, -1, sizeof(t));
        return solve(0, 1, 2, prices);
    }
};