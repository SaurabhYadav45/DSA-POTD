class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()){
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();

        int l = 0;
        int r = m;
        while(l <= r){
            int mid = l + (r-l)/2;
            int px = mid;        // No. of element we take from nums1 in first half
            int py = (m+n+1)/2 - px; //rest we take from nums2

            int x1 = (px == 0) ? INT_MIN : nums1[px-1];
            int x2 = (py == 0) ? INT_MIN : nums2[py-1];
            int x3 = (px == m) ? INT_MAX : nums1[px];
            int x4 = (py == n) ? INT_MAX : nums2[py];

            if(x1 <= x4 && x2 <= x3){
                if((m+n)%2 == 0){
                    return (max(x1, x2) + min(x3, x4))/2.0;
                }
                return max(x1, x2);
            }
            else if(x1 > x4){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return -1;
    }
};




//            ************ Better Approach *************

// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int m = nums1.size();
//         int n = nums2.size();
//         int i=0, j=0, k=0;

//         int idx1 = (m+n)/2-1;
//         int idx2 = (m+n)/2;
//         int element1 = 0;
//         int element2 = 0;
//         while(i < m && j <n){
//             if(nums1[i] < nums2[j]){
//                 if(k == idx1) element1 = nums1[i];
//                 if(k == idx2) element2 = nums1[i];
//                 i++;
//             }
//             else{
//                 if(k == idx1) element1 = nums2[j];
//                 if(k == idx2) element2 = nums2[j];
//                 j++;
//             }
//             k++;
//         }

//         while( i < m){
//             if(k == idx1) element1 = nums1[i];
//             if(k == idx2) element2 = nums1[i];
//             i++;
//             k++;
//         }
//         while( j < n){
//             if(k == idx1) element1 = nums2[j];
//             if(k == idx2) element2 = nums2[j];
//             j++;
//             k++;
//         }
        
//         double median=0;
//         if((m+n) % 2 != 0){
//             median = (double)element2;
//         }
//         else{
//            median = (double)(element1 + element2)/2;
//         }
//         return median;
//     }
// };



//         ******************* Brute Force *******************

// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         vector<int>nums;
//         int n1 = nums1.size();
//         int n2 = nums2.size();
//         int i=0, j=0;
//         while(i < n1 && j <n2){
//             if(nums1[i] < nums2[j]){
//                 nums.push_back(nums1[i]);
//                 i++;
//             }
//             else{
//                 nums.push_back(nums2[j]);
//                 j++;
//             }
//         }

//         while( i < n1){
//             nums.push_back(nums1[i]);
//             i++;
//         }
//         while( j < n2){
//             nums.push_back(nums2[j]);
//             j++;
//         }
        
//         int n = nums.size();
//         double median=0;
//         if(nums.size() % 2 != 0){
//             median = (double)nums[n/2];
//         }
//         else{
//            median = (double)(nums[(n/2)] + nums[(n/2)-1])/2;
//         }
//         return median;
//     }
// };