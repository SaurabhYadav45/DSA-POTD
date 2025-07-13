// class Solution {
// public:
//     int numOfBouquetsHelper(vector<int>& bloomDay, int k, int mid){
//         int numOfBouquets = 0;
//         int count =0;
//         for(int i=0; i<bloomDay.size(); i++){
//             if(bloomDay[i] <= mid){
//                 count++;
//             }
//             else{
//                 count =0;
//             }
            
//             if(count == k){
//                 numOfBouquets++;
//                 count=0;
//             }
//         }
//         return numOfBouquets;
//     }
//     int minDays(vector<int>& bloomDay, int m, int k) {
//         int n= bloomDay.size();
//         if ((long long)m * k > n) return -1;
         
//         int start = 0;
//         int end = 0;
//         int minDays=0;
//         for (int day : bloomDay) {
//             end = max(end, day);
//         }
//         // sort(bloomDay.begin(), bloomDay.end());
//         while(start <= end){
//             int mid = (start + end)/2;
//             int numOfBouquets = numOfBouquetsHelper(bloomDay, k, mid);
//             if(numOfBouquets >= m){
//                 minDays = mid;
//                 end  = mid-1;
//             }
//             else{
//                 start = mid+1;
//             }
//         }
//         return minDays;
//     }
// };

//              ***************** Optimal : Binary Serach ****************

class Solution {
public:
    bool mBouquetsPossible(vector<int>& bloomDay, int m, int k, int day){
        int bouquetCount = 0;
        int flowerCount = 0;
        for(int& num : bloomDay){
            if(num <= day) flowerCount++;
            else flowerCount = 0;

            if(flowerCount == k){
                bouquetCount++;
                flowerCount = 0;
            }
        }
        if(bouquetCount >= m) return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int result = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(mBouquetsPossible(bloomDay, m, k, mid)){
                result = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return  result;
    }
};


//                ************* Brute Force *****************

// class Solution {
// public:
//     int minDays(vector<int>& bloomDay, int m, int k) {
//         int n = bloomDay.size();
//         int min = *min_element(bloomDay.begin(), bloomDay.end());
//         int max = *max_element(bloomDay.begin(), bloomDay.end());
//         int result = -1;
//         for(int day = min; day<=max; day++){
//             int flowerCount = 0;
//             int bouquetCount = 0;
//             for(int& num : bloomDay){
//                 if(num <= day) flowerCount++;
//                 else flowerCount = 0;

//                 if(flowerCount == k){
//                     bouquetCount++;
//                     flowerCount = 0;
//                 }
//             }
//             if(bouquetCount >= m){
//                 result = day;
//                 break;
//             }
//         }
//         return  result;
//     }
// };