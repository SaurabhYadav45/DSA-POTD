class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& nums) {
        n=nums.size();
        map<int,set<int>> mp1,mp2;
        for(auto&x:nums){
            int a=x[0],b=x[1];
            mp1[a].insert(b);
            mp2[b].insert(a);
        }
        int ans=0;
        for(auto&x:nums){
            int a=x[0],b=x[1];
            if((mp1[a].size()>2 && mp2[b].size()>2 && mp1[a].find(b)!=mp1[a].end() && mp2[b].find(a)!=mp2[b].end()) && ((*mp1[a].begin())!=b && (*(--mp1[a].end()))!=b) && ((*mp2[b].begin())!=a && (*(--mp2[b].end()))!=a)){
                ans++;
            }
        }
        return ans;
    }
};