// class Solution {
// public:
//     bool isPossibleSolution(vector<int>& nums, int n, int k, int sol){
//         int count =1;
//         int sumPage=0;
//         for(int i =0; i<n; i++){
//             if(nums[i] > sol){
//                 return false;
//             }
//             if(nums[i] + sumPage > sol){
//                 count++;
//                 sumPage = nums[i];
//                 if(count > k){
//                     return false;
//                 }
//             }
//             else{
//                 sumPage+= nums[i];
//             }
//         }
//         return true;
//     }

//     int splitArray(vector<int>& nums, int k) {
//         int n= nums.size();
//         // sort(nums.begin(), nums.end());

//         if(k>n){
//             return -1;
//         }
//         int start = 0;
//         int end = accumulate(nums.begin(), nums.end(), 0);
//         int ans =-1;
//         while(start <= end){
//             int mid = start + (end-start)/2;
//             if(isPossibleSolution(nums, n, k, mid)){
//                 ans = mid;
//                 end = mid -1;
//             }
//             else{
//                 start =  mid +1;
//             }
//         }
//         return ans ;
//     }
// };


class Solution {
public:
    int solve(vector<int> &arr, long long maxPage){
        int student = 1;
        long long pageSum = 0;
        for(int i=0; i<arr.size(); i++){
            if(pageSum + arr[i] <= maxPage){
                pageSum += arr[i];
            }
            else{
                student++;
                pageSum = arr[i];
            }
        }
        return student;
    }
    int splitArray(vector<int>& arr, int k) {
        if(k > arr.size()) return -1;
        
        long long sum = 0;
        long long minPage = -1;
        for(int& num: arr){
            sum += num;
            minPage = max(minPage, (long long)num);
        }
        
        long long low = minPage;
        long long high = sum;
        long long result = -1;
        while(low <= high){
            long long mid = low + (high-low)/2;
            int student = solve(arr, mid);
            if(student <= k){
                result = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return result;
    }
};