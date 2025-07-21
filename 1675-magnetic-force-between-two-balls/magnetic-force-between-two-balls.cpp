class Solution {
public:
    bool canPlace(vector<int>& position, int m, int mid){
        int prevPos = position[0];
        int count = 1;
        for(int i=1; i<position.size(); i++){
            int currPos = position[i];
            if(currPos - prevPos >= mid){
                count++;
                prevPos = currPos;
            }
            if(count == m)break;
        }
        return count == m;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int low = 1;
        int min = *min_element(position.begin(), position.end());
        int max = *max_element(position.begin(), position.end());
        int high = max - min;

        int result = 0;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(canPlace(position, m, mid)){
                result = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return result;
    }
};



// class Solution {
// public:
//     bool ballGetPlaced(vector<int>& position, int mid, int m){
//         int prevPos = position[0];
//         int count = 1;
//         for(int i=1; i< position.size() && count < m; i++){
//             int currPos = position[i];
//             if(currPos - prevPos >= mid){
//                 count += 1;
//                 prevPos = currPos;
//             }
//         }
//         return count == m;
//     }
    
//     int maxDistance(vector<int>& position, int m) {
//         sort(position.begin(), position.end());
//         int n= position.size();
//         int start =0;
//         int end = ceil(position[n-1]/(m-1.0));
//         int ans = 0;
//         while(start <= end){
//             int mid  = start + (end-start)/2;
//             if(ballGetPlaced(position, mid, m)){
//                 ans = mid;
//                 start = mid + 1;
//             }
//             else{
//                 end  = mid-1;
//             }
//         }
//         return ans;
//     }
// };