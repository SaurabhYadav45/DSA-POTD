class Solution {
public:
    bool canRun(int n, vector<int>& batteries, long long mid){
        long long requiredTime = mid * n;
        long long totalTime=0;
        for(auto& t: batteries){
            totalTime += min((long long)t, mid);
            if(totalTime >= requiredTime){
                return true;
            }
        }
        return false;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long low = *min_element(batteries.begin(), batteries.end());
        long long high = accumulate(batteries.begin(), batteries.end(), 0LL)/n;
        long long result = 0;

        while(low <= high){
            long long mid = low + (high-low)/2;
            if(canRun(n, batteries, mid)){
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