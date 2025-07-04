class Solution {
public:
    void getLeftMaxArray(vector<int>& height, vector<int>&leftMax){
        int n = height.size();
        leftMax[0] = height[0];
        for(int i=1; i<n; i++){
            leftMax[i] = max(leftMax[i-1], height[i]);
        }
    }

    void getRightMaxArray(vector<int>& height, vector<int>&rightMax){
        int n = height.size();
        rightMax[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--){
            rightMax[i] = max(rightMax[i+1], height[i]);
        }
    }
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>leftMax(n,0);
        vector<int>rightMax(n, 0);
        getLeftMaxArray(height, leftMax);
        getRightMaxArray(height, rightMax);

        int result=0;

        for(int i=0; i<n; i++){
            int area = min(leftMax[i], rightMax[i]) - height[i];
            result += area;
        }
        return result;
    }
};