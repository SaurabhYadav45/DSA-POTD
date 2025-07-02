class Solution {
public:
    string removeDuplicates(string s) {
        string result = "";
        result.push_back(s[0]);
        for(int i=1; i<s.length(); i++){
            if(!result.empty() && s[i] == result.back()){
                result.pop_back();
            }
            else{
                result.push_back(s[i]);
            }
        }
        return result;
    }
};