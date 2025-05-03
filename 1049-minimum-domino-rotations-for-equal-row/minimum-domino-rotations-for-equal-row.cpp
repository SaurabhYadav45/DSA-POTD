class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int result = INT_MAX;
        int minOp = INT_MAX;
        for(int i=1; i<=6; i++){
            int topSwap = 0;
            int bottomSwap = 0;
            bool flag = true;
            for(int j=0; j<tops.size(); j++){
                if(tops[j] != i && bottoms[j] != i){
                    flag = false;
                    break;
                }
                if(tops[j] != i){
                    topSwap++;
                }
                if(bottoms[j] != i){
                    bottomSwap++;
                }
            }
            if(flag == true){
                minOp = min(topSwap, bottomSwap);
                result = min(result, minOp);
            }
        }
        return result == INT_MAX ? -1 : result;
    }
};