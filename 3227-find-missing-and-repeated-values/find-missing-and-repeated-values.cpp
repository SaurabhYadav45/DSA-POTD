class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        // vector<int>result(2);
        int n = grid.size();

        vector<int>arr(n*n + 1, 0);

        int a = 0;
        int b = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int num = grid[i][j];
                if(arr[num] == -1){
                    a = num;
                }
                arr[num] = -1;
            }
        }

        for(int i=1; i<=n*n; i++){
            if(arr[i] >= 0){
                b = i;
            }
        }

        return {a, b};
    }
};