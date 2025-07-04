class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        // base case
        if(k == 1) return 'a';

        long long  len = 1;
        int opType;
        long long newK;
        for(int i=0; i<operations.size(); i++){
            len *= 2;
            if(len >= k){
                opType = operations[i];
                newK = k - len/2;
                break;
            }
        }

        char ch = kthCharacter(newK, operations);
        if(opType == 0){
            return ch;
        }
        else{
            if(ch == 'z') return 'a';
            else return ch + 1;
        }
    }
};