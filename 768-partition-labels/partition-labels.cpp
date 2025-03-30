class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<vector<int>>intervals;
        unordered_map<char, pair<int, int>>mp;

        for(int i=0; i<s.length(); i++){
            if(mp.find(s[i]) == mp.end()){
                mp[s[i]] = {i, i};
            }
            else{
                mp[s[i]].second = i;
            }
        }

        for(auto& it: mp){
            pair<int, int>p = it.second;
            int start = p.first;
            int end = p.second;
            intervals.push_back({start, end});
        }

        sort(intervals.begin(), intervals.end());
        vector<vector<int>>result;
        result.push_back(intervals[0]);

        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] < result.back()[1]){
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }
            else{
                result.push_back(intervals[i]);
            }
        }

        vector<int>res(result.size(), 0);

        for(int i=0; i<result.size(); i++){
            res[i] = result[i][1]-result[i][0]+1;
        }
        return res;
    }
};