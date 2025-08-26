class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int m = dimensions.size();
        int n = dimensions[0].size();
        long long maxArea = INT_MIN;
        double longestDiagonal = INT_MIN;
        for(int i=0; i<m; i++){
            long long length = dimensions[i][0];
            long long breadth = dimensions[i][1];
            double diagonal = sqrt((length*length) + (breadth*breadth));

            if(diagonal > longestDiagonal){
                longestDiagonal = diagonal;
                maxArea = length*breadth;
            }
            else if(diagonal == longestDiagonal){
                maxArea = max(maxArea, length*breadth);
            }
        }
        return maxArea;
    }
};