class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        // vector<char> equ(26);
        // for (int i = 0; i < 26; i++) 
        // equ[i] = 'a' + i;
        unordered_map<int, char>mp;
        for (int i = 0; i < 26; i++){
            mp[i] = 'a'+i;
        }


        int s = s1.size();
        for (int i = 0; i < s; i++) {
          
            char r1 = mp[s1[i]-'a'];
            char r2 = mp[s2[i] - 'a'];

            char newchar = min(r1, r2);
            char old = max(r1, r2);

            for (int j = 0; j < 26; j++) {
                if (mp[j] == old)
                    mp[j] = newchar;
            }
        }

        string result = "";
        for (char c : baseStr) {
            result += mp[c - 'a'];
        }

        return result;
    }
};