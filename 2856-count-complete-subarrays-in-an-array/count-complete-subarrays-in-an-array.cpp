
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n  = nums.size();
        unordered_set<int>st{nums.begin(), nums.end()};
        int distinct_size = st.size();
        int count = 0;
        unordered_map<int, int>mp;

        int i=0; 
        int j=0;
        while(j < n){
            mp[nums[j]]++;
            while(mp.size() == distinct_size){
                count += n - j;
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            
            j++;
        }

        return count;
    }
};



// class Solution {
// public:
//     int countCompleteSubarrays(vector<int>& nums) {
//         int n  = nums.size();
//         unordered_set<int>st{nums.begin(), nums.end()};
//         int distinct_size = st.size();

//         int count = 0;

//         for(int i=0; i<n; i++){
//             unordered_set<int>temp;
//             for(int j=i; j<n; j++){
//                 temp.insert(nums[j]);
//                 if(temp.size() == distinct_size){
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };