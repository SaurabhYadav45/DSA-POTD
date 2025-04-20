class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int>mp;

        for(int& ans: answers){
            mp[ans]++;
        }

        int result=0;

        for(auto& it: mp){
            int count = it.second;
            int x = it.first;
            int no_of_groups = ceil((double)count/(x+1));
            result += no_of_groups*(x+1);
        }
        return result;
    }
};