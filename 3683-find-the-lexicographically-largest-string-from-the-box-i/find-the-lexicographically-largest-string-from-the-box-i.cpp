// class Solution {
// public:
//     string answerString(string word, int numFriends) {
//         if (numFriends == 1) {
//             return word;
//         }
//         int n = word.size();
//         string res;
//         for (int i = 0; i < n; i++) {
//             res = max(res, word.substr(i, min(n - numFriends + 1, n - i)));
//         }
//         return res;
//     }
// };


class Solution {
public:
    string answerString(string word, int numFriends) {

        if(numFriends==1){
            return word;
        }
        
       int n=word.length();
       int maxi=n-numFriends+1;
       vector<string>v;

       string s=word.substr(0,maxi-1);
       string  ans=s;
       for(int i=0;i<=n-maxi;i++){
            s+=word[maxi+i-1];
            // v.push_back(s);
            if(s>ans)ans =s;
            s.erase(0,1);
       }
       
    
       while(s.size()){
            if(s>ans)ans =s;
        //   v.push_back(s);
          s.erase(0,1);

       }

        // sort(v.begin(),v.end());

        return ans;

    }
};