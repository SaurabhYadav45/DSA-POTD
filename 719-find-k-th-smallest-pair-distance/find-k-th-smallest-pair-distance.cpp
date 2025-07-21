class Solution {
public:
    int slidingWindowCount(vector<int>& nums, int mid){
        int i=0;
        int j = 1;
        int count = 0;
        while(j < nums.size()){
            while(nums[j]-nums[i] > mid){
                i++;
            }
            count += j-i;
            j++;
        }
        return count;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int l = 0;
        int h = nums[n-1]- nums[0];
        int result = 0;
        while(l <= h){
            int mid = l + (h-l)/2;
            int count = slidingWindowCount(nums, mid);
            if(count < k){
                l = mid+1;
            }
            else{
                result = mid;
                h = mid-1;
            }
        }
        return result;
    }
};



// class Solution {
// public:
//     int smallestDistancePair(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<int>vec;
//         for(int i=0; i<n; i++){
//             for(int j=i+1; j<n; j++){
//                 vec.push_back(abs(nums[j]-nums[i]));
//             }
//         }

//         nth_element(vec.begin(), vec.begin()+(k-1), vec.end());
//         return vec[k-1];
//     }
// };



// class Solution {
// public:
//     int smallestDistancePair(vector<int>& nums, int k) {
//         int n = nums.size();
//         priority_queue<int, vector<int>, greater<int>>pq;
        
//         for(int i=0; i<n; i++){
//             for(int j=i+1; j<n; j++){
//                 pq.push(abs(nums[j]-nums[i]));
//             }
//         }

//         while(!pq.empty() && k > 1){
//             pq.pop();
//             k--;
//         }
//         return pq.top();
//     }
// };
