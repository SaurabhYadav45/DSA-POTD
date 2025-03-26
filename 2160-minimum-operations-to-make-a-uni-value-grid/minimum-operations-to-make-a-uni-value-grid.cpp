class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int>arr;

        int minOp = 0;

        int rem = grid[0][0] % x;

        for(auto& vec : grid){
            for(int& num : vec){
                if(num % x != rem){
                    return -1;
                }
                arr.push_back(num); 
            }
        }

        sort(arr.begin(), arr.end());

        int median = arr[(m*n)/2];

        for(int& num : arr){
            if(num == median) continue;
            int count = 0;
            while(num != median){
                if(num > median){
                    num = abs(num - x);
                }
                else{
                    num = num + x;
                }
                count++;
            }
            minOp += count;
        }
        return minOp;
    }
};