class Solution {
public:
    int maxDistance(string s, int k) {
        int dist = 0;
        int north  = 0;
        int south = 0;
        int east = 0;
        int west = 0;

        int maxDist =0;

        for(int i=0; i<s.length(); i++){
            char ch = s[i];
            if(ch == 'N') north++;
            else if(ch == 'S') south++;
            else if(ch == 'E') east++;
            else if(ch == 'W') west++;

            int step = i+1;
            int dist = abs(north - south) + abs(east - west);
            int wasted = step - dist;
            int extra = 0;
            if(wasted != 0){
                extra = min(wasted, 2*k);
            }

            int finalDist = dist + extra;
            maxDist = max(maxDist, finalDist);
        }
        return maxDist;
    }
};