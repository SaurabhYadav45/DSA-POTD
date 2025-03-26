class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
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

        int size = arr.size();
        // sort(arr.begin(), arr.end());
        // Partial sorting
        nth_element(arr.begin(), arr.begin() + size/2, arr.end());

        int median = arr[size/2];

        for(int& num : arr){
            minOp += (abs(median-num))/x;
        }
        return minOp;
    }
};