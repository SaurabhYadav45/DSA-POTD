class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.length();
        vector<string>result;
        int i=0;
        string temp = "";
        while(i<n){
            temp.push_back(s[i]);
            if(temp.length() == k){
                result.push_back(temp);
                temp.clear();
            }
            i++;
        }
        int rem = n % k;
        if(rem == 0){
            return result;
        }

        int m = temp.length();
        if(m < k){
            int x = k-m;
            for(int i=0; i<x; i++){
                temp.push_back(fill);
            }
            result.push_back(temp);
        }
        return result;
    }
};