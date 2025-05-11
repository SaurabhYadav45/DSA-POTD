class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n=arr.size();

        
        // if(n == 0 || n == 1 || n == 2) return false;
        // for(int i=0; i<n-2; i++){
        //     if((arr[i]%2 == 1)&& (arr[i+1]%2 == 1)&&(arr[i+2]%2 == 1)){
        //         return true;
        //     }
        // }
        // return false;

        // Method-2
        int oddCount =0;
        for(int i=0; i<n; i++){
            if(arr[i] % 2 != 0){
                oddCount++;
                if(oddCount == 3) return true;
            }
            else{
                oddCount = 0;
            }
        }
        return false;
    }
};