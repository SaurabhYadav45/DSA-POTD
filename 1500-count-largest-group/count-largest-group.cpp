class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int>mp;
        int maxValue = 0;

        for(int i=1; i<=n; i++){
            int sum = 0;
            int num = i;
            while(num > 0){
                sum += num%10;
                num /= 10;
            }
            mp[sum]++;
            maxValue = max(maxValue, mp[sum]);
        }
        

        int count=0;
        for(auto& it: mp){
            if(it.second == maxValue)count++;
        }
        return count;
    }
};