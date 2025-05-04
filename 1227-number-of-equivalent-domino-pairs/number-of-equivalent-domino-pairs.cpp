class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n = dominoes.size();
        int result = 0;
        unordered_map<string, int>mp;

        for(auto& vec: dominoes){
            string s = "";
            s.push_back(vec[0]);
            s.push_back(vec[1]);
            sort(s.begin(), s.end());
            mp[s]++;
        }

        for(auto& it : mp){
            int count  = it.second;
            result += (count*(count-1))/2;
        }
        return result;
    }
};



// class Solution {
// public:
//     int numEquivDominoPairs(vector<vector<int>>& dominoes) {
//         int n = dominoes.size();
//         int count = 0;

//         for(int i=0; i<n; i++){
//             for(int j=i+1; j<n; j++){
//                 int a = dominoes[i][0];
//                 int b = dominoes[i][1];
//                 int c = dominoes[j][0];
//                 int d = dominoes[j][1];
//                 if(a == c && b == d  || a == d && b == c){
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };
