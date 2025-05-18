class Solution {
public:
    
    int sumOfDigit(int num){
        int sum = 0;
        while(num > 0){
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        vector<pair<int, int>>vec;

        for(int i=0; i<nums.size(); i++){
            int num = nums[i];
            int sum = sumOfDigit(num);
            vec.push_back({sum, num});
        }

        sort(vec.begin(), vec.end(), [&nums](const pair<int, int>&a, const pair<int, int>&b){
            if(a.first == b.first){
                return a.second < b.second;
            }
            return a.first < b.first;
        });

        int swapp = 0;
        unordered_map<int, int>mp;
        for(int i=0; i<nums.size(); i++){
            int num = nums[i];
            mp[num] = i;
        }

        for(int i=0; i<nums.size(); i++){
            if(nums[i] != vec[i].second){
                int idx = mp[vec[i].second];
                swap(nums[i], nums[idx]);
                mp[nums[i]] = i;
                mp[nums[idx]] = idx;
                swapp++;
            }
        }
        return swapp;  
    }
};





// class Solution {
// public:
    
//     int sumOfDigit(int num){
//         int sum = 0;
//         while(num > 0){
//             sum += num % 10;
//             num /= 10;
//         }
//         return sum;
//     }
//     int minSwaps(vector<int>& nums) {
//         vector<pair<int, int>>vec;

//         for(int i=0; i<nums.size(); i++){
//             int num = nums[i];
//             int sum = sumOfDigit(num);
//             vec.push_back({sum, i});
//         }

//         sort(vec.begin(), vec.end(), [&nums](const pair<int, int>&a, const pair<int, int>&b){
//             if(a.first == b.first){
//                 return nums[a.second] < nums[b.second];
//             }
//             return a.first < b.first;
//         });

//         // vector<bool>visited(nums.size(), false);
//         int swap = 0;
//         unordered_map<int, int>mp;
//         for(int i=0; i<nums.size(); i++){
//             int num = nums[i];
//             mp[num] = i;
//         }

//         for(int i=0; i<nums.size(); i++){
//             if(nums[i] != vec[i].)
//         }

//         // for(int i=0; i<nums.size(); i++){
//         //     if(visited[i] || vec[i].second == i){
//         //         continue;
//         //     }

//         //     int cycle = 0;
//         //     int j = i;
//         //     while(!visited[j]){
//         //         visited[j] = true;
//         //         j = vec[j].second;
//         //         cycle++;
//         //     }

//         //     if(cycle > 0){
//         //         swap += (cycle-1);
//         //     }
//         // }
//         return swap;
        
//     }
// };