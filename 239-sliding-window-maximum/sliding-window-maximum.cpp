class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>>pq;
        int n = nums.size();
        vector<int>result;
        for(int i=0; i<n; i++){
            // step-1
            while(!pq.empty() && pq.top().second <= i-k){
                pq.pop();
            }
            // step-3
            pq.push({nums[i], i});
            // step-4
            if(i >= k-1){
                result.push_back(pq.top().first);
            }
        }
        return result;
    }
};




// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         deque<int>dq;
//         int n = nums.size();
//         vector<int>result;
//         for(int i=0; i<n; i++){
//             // step-1
//             while(!dq.empty() && dq.front() <= i-k){
//                 dq.pop_front();
//             }
//             // step-2
//             while(!dq.empty() && nums[i] > nums[dq.back()]){
//                 dq.pop_back();
//             }
//             // step-3
//             dq.push_back(i);
//             // step-4
//             if(i >= k-1){
//                 result.push_back(nums[dq.front()]);
//             }
//         }
//         return result;
//     }
// };


// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         vector<int>ans;
//         deque<int>dq;
//         // First window ko process karo
//         for(int i =0; i<k; i++){
//             int element = nums[i];
//             while(!dq.empty() && element > nums[dq.back()]){
//                 dq.pop_back();
//             }
//             dq.push_back(i);
//         }
        
//         // Remaining window ko process karo
//         // Answer ko store 
//         // removal and Addition
//         for(int i=k; i<nums.size(); i++){
//             // ans store
//             ans.push_back(nums[dq.front()]);
//             // Removal
//             if(i-dq.front() >= k){
//                 dq.pop_front();
//             }
//             // chhote element ko remove karo
//             int element = nums[i];
//             while(!dq.empty() && element > nums[dq.back()]){
//                 dq.pop_back();
//             }
//             // addition
//             dq.push_back(i);
//         }
//         // Last ans store karo
//         ans.push_back(nums[dq.front()]);
//         return ans;
//     }
// };