// class Solution {
// public:
//     bool isValid(string& s){
//         for(int i=0; i<s.length(); i++){
//             char ch = s[i];
//             if(!isalnum(ch) && !(ch == '_')){
//                 return false;
//             }
//         }
//         return true;
//     }
//     // static bool myComp(pair<string, string>&a, pair<string, string>&b){
//     //     if(a.second == b.second){
//     //         return a.first < b.first;
//     //     }
//     //     return a.second < b.second;
//     // }
//     vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
//         auto  lambda = [](pair<string, string>&a, pair<string, string>&b){
//             if(a.second == b.second){
//                 return a.first < b.first;
//             }
//             return a.second < b.second;
//         };
//         unordered_set<string>st;
//         st.insert("electronics");
//         st.insert("grocery");
//         st.insert("pharmacy");
//         st.insert("restaurant");

//         vector<string>result;
//         vector<pair<string, string>>pairs;

//         for(int i=0; i<code.size(); i++){
//             if(code[i].empty()) continue;
//             if(isValid(code[i]) && st.find(businessLine[i]) != st.end() && isActive[i] == true){
//                 pairs.push_back({code[i], businessLine[i]});
//             }
//         }
//         sort(pairs.begin(), pairs.end(), lambda);
//         for(auto& pair: pairs){
//             result.push_back(pair.first);
//         }
//         return result;
//     }
// };



class Solution {
public:
    bool isValid(string& s){
        for(int i=0; i<s.length(); i++){
            char ch = s[i];
            if(!isalnum(ch) && !(ch == '_')){
                return false;
            }
        }
        return true;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        auto  lambda = [&](pair<string, int>&a, pair<string, int>&b){
            if(businessLine[a.second] == businessLine[b.second]){
                return a.first < b.first;
            }
            return businessLine[a.second] < businessLine[b.second];
        };
        unordered_set<string>st;
        st.insert("electronics");
        st.insert("grocery");
        st.insert("pharmacy");
        st.insert("restaurant");

        vector<string>result;
        vector<pair<string, int>>pairs;

        for(int i=0; i<code.size(); i++){
            if(code[i].empty()) continue;
            if(isValid(code[i]) && st.find(businessLine[i]) != st.end() && isActive[i] == true){
                pairs.push_back({code[i], i});
            }
        }
        sort(pairs.begin(), pairs.end(), lambda);
        for(auto& pair: pairs){
            result.push_back(pair.first);
        }
        return result;
    }
};