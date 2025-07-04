class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int result=0;

        int i = 0;
        int j = n-1;
        int leftMax = -1;
        int rightMax = -1;

        while(i < j){
            leftMax = max(leftMax, height[i]);
            rightMax = max(rightMax, height[j]);
            int area = 0;
            if(leftMax <= rightMax){
                area = leftMax - height[i];
                i++;
            }
            else{
                area = rightMax - height[j];
                j--;
            }
            result += area;
        }
        return result;
    }
};





// class Solution {
// public:
//     void getLeftMaxArray(vector<int>& height, vector<int>&leftMax){
//         int n = height.size();
//         leftMax[0] = height[0];
//         for(int i=1; i<n; i++){
//             leftMax[i] = max(leftMax[i-1], height[i]);
//         }
//     }

//     void getRightMaxArray(vector<int>& height, vector<int>&rightMax){
//         int n = height.size();
//         rightMax[n-1] = height[n-1];
//         for(int i=n-2; i>=0; i--){
//             rightMax[i] = max(rightMax[i+1], height[i]);
//         }
//     }
//     int trap(vector<int>& height) {
//         int n = height.size();
        
//         int result=0;

//         for(int i=0; i<n; i++){
//             int area = min(leftMax[i], rightMax[i]) - height[i];
//             result += area;
//         }
//         return result;
//     }
// };