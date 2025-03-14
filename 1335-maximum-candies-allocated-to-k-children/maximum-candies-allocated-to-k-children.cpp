class Solution {
public:
    bool canDist(vector<int>& candies, int mid, long long k){
        int n = candies.size();

        for(int i=0; i<n; i++){
            k -= candies[i]/mid;
        }

        if(k <= 0){
            return true;
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();

        int maxC = 0;
        long long total = 0;
        for(int i=0; i<n; i++){
            total += candies[i];
            maxC = max(maxC, candies[i]);
        }

        if(total < k){
            return 0;
        }

        int l = 1;
        int r = maxC;
        int result = 0;

        while(l <= r){
            int mid = (l + r)/2;

            if(canDist(candies, mid, k)){
                result = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }

        return result;;
    }
};



//                      Brute Force


// class Solution {
// public:
//     int maximumCandies(vector<int>& candies, long long k) {
//         int n = candies.size();

//         int maxC = 0;
//         for(int i=0; i<n; i++){
//             maxC = max(maxC, candies[i]);
//         }

//         for(int i = maxC; i>=1; i--){
//             long long count = 0;
//             for(int j=0; j<n; j++){
//                 count += candies[j]/i;
//             }

//             if(count >= k){
//                 return i;
//             }
//         }
//         return 0;
//     }
// };