class Solution{
public:
    void findNSL(vector<int> &heights, vector<int>&NSL){
        int n = heights.size();
        stack<int>st;
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[i] <= heights[st.top()]){
                st.pop();
            }
            NSL[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }

    void findNSR(vector<int> &heights, vector<int>&NSR){
        int n = heights.size();
        stack<int>st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[i] <= heights[st.top()]){
                st.pop();
            }
            NSR[i] = st.empty() ? n : st.top();
            st.push(i);
        }
    }
    int largestRectangleArea(vector<int> &heights){
        int n = heights.size();
        vector<int>NSL(n, 0);
        vector<int>NSR(n, 0);
        findNSL(heights, NSL);
        findNSR(heights, NSR);

        int result = INT_MIN;
        for(int i=0; i<n; i++){
            int width = NSR[i] - NSL[i] -1;
            int area = width*heights[i];
            result = max(result, area);
        }
        return result;
    }
};








// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int area = INT_MIN;

//         for (int i = 0; i < heights.size(); i++)
//         {
//             int j = i-1;
//             int k = i+1;
//             int a = 1; // Reset 'a' for each histogram bar

//             // Move left while the bar is higher
//             while (j >= 0 && heights[j] >= heights[i])
//             {
//                 a++;
//                 j--;
//             }

//             // Move right while the bar is higher
//             while (k < heights.size() && heights[k] >= heights[i])
//             {
//                 a++;
//                 k++;
//             }

//             int multi = heights[i] * a;
//             area = std::max(area, multi);
//         }

//         return area;
//     }
// };



// class Solution
// {
// public:
//     vector<int> nextSmaller(vector<int> &arr, int n)
//     {
//         stack<int> st;
//         vector<int> ans(n);
//         st.push(-1);
//         for (int i = n - 1; i >= 0; i--)
//         {
//             int curr = arr[i];
//             while (st.top() != -1 && arr[st.top()] >= curr)
//             {
//                 st.pop();
//             }
//             if (st.top() == -1)
//                 ans[i] = n;
//             else
//                 ans[i] = st.top();
//             st.push(i);
//         }
//         return ans;
//     }
//     // prev Smaller
//     vector<int> prevSmaller(vector<int> &arr, int n)
//     {
//         stack<int> st;
//         vector<int> ans(n);
//         st.push(-1);
//         for (int i = 0; i < n; i++)
//         {
//             int curr = arr[i];
//             while (st.top() != -1 && arr[st.top()] >= curr)
//             {
//                 st.pop();
//             }

//             ans[i] = st.top();
//             st.push(i);
//         }
//         return ans;
//     }
//     int largestRectangleArea(vector<int> &heights)
//     {
//         int n=heights.size();
//         if(n==1)return heights[0];
//         vector<int>  leftToRight=prevSmaller(heights,n);
//         vector<int> rightToLeft=nextSmaller(heights,n);
//         // rev krdo
//         // reverse(rightToLeft.begin(),rightToLeft.end());
//         vector<int>area(leftToRight.size());
//         for(int i=0;i<leftToRight.size();i++){
//             int width=rightToLeft[i]-leftToRight[i]-1;
//             int length=heights[i];
//             area[i]=width*length;
//         }
//         int maxi=INT_MIN;
//         for(int i=0;i<area.size();i++){
//             maxi=max(maxi,area[i]);
//         }
//         return maxi;
        
//     }
// };