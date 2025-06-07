class Solution {
public:
    struct myComp{
        bool operator()(pair<char, int>&a, pair<char, int>&b){
            if (a.first != b.first) {
            return a.first > b.first;
        }
        return a.second < b.second;
        }
    };
    string clearStars(string s) {
        int n = s.length();
        priority_queue<pair<char,int>, vector<pair<char,int>>, myComp>pq;
    
        for(int i=0; i<n; i++){
            if(s[i] == '*'){
                int idx = pq.top().second;
                pq.pop();
                s[idx] = '*';
            }
            else{
                pq.push({s[i], i});
            }
        }

        string result = "";
        
        for(int i=0; i<n; i++){
            if(s[i] != '*'){
                result.push_back(s[i]);
            }
        }
        return result;
    }
};