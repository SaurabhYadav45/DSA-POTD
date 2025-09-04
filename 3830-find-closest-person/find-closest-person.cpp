class Solution {
public:
    int findClosest(int x, int y, int z) {
        int diff1 = abs(z-x);
        int diff2 = abs(y-z);
        if(diff1 < diff2){
            return 1;
        }
        else if(diff1 == diff2){
            return 0;
        }
        return 2;
    }
};