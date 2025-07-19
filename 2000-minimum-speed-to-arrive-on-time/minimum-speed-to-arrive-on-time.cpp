class Solution {
public:
    bool isPossible(vector<int>& dist, double hour, int speed){
        int n = dist.size();
        double time = 0;
        for(int i=0; i<n-1; i++){
            double t = (double)dist[i]/(double)speed;
            time += ceil(t);
        }
        time += (double)dist[n-1]/(double)speed;
        return time <= hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low = 1;
        int high = 10000000;
        int result = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(isPossible(dist, hour, mid)){
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