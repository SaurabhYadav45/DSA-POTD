class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>vec;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                vec.push_back(abs(nums[j]-nums[i]));
            }
        }

        nth_element(vec.begin(), vec.begin()+(k-1), vec.end());
        return vec[k-1];
    }
};



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
