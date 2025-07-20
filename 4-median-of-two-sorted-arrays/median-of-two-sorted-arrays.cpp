class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>nums;
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i=0, j=0;
        while(i < n1 && j <n2){
            if(nums1[i] < nums2[j]){
                nums.push_back(nums1[i]);
                i++;
            }
            else{
                nums.push_back(nums2[j]);
                j++;
            }
        }

        while( i < n1){
            nums.push_back(nums1[i]);
            i++;
        }
        while( j < n2){
            nums.push_back(nums2[j]);
            j++;
        }
        
        int n = nums.size();
        double median=0;
        if(nums.size() % 2 != 0){
            median = (double)nums[n/2];
        }
        else{
           median = (double)(nums[(n/2)] + nums[(n/2)-1])/2;
        }
        return median;
    }
};