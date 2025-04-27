class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int m, vector<vector<int>>& q) {
        vector<pair<int,int>> mp;
        int s = -1, e = -1;
        int n1 = nums.size();
        
        for(int i = 0; i < n1; i++) {
            int d = nums[i] + m;
            int s1 = i + 1;
            int e1 = n1 - 1;
            int z = -1;
            
            while(s1 <= e1) {
                int mid = s1 + (e1 - s1) / 2;
                if(nums[mid] <= d) {
                    s1 = mid + 1;
                    z = mid;
                } else {
                    e1 = mid - 1;
                }
            }
            
            // cout << s << " " << e << " " << i << " " << z << endl; // Debug: can comment or remove
            
            if(z != -1 && z != i) {
                if(z > e) {
                    e = z;
                    if(s == -1) s = i;
                }
            }
            if(z == -1 && i == e) {
                mp.push_back({s, e});
                s = -1;
                e = -1;
            }
        }
        
        vector<bool> ans;
        
        for(int i = 0; i < q.size(); i++) {
            int st = min(q[i][0],q[i][1]);
            int ee = max(q[i][1],q[i][0]);
            
            if(st == ee) {
                ans.push_back(true);
                continue;
            }
            
            bool f = false;
            int s1 = 0;
            int e1 = mp.size() - 1;
            
            while(s1 <= e1) {
                int mid = s1 + (e1 - s1) / 2;
                
                if(mp[mid].first <= st && mp[mid].second >= st) {
                    if(mp[mid].second >= ee) f = true;
                    break;
                } else if(mp[mid].first > st) {
                    e1 = mid - 1;
                } else if(mp[mid].second < st) {
                    s1 = mid + 1;
                }
            }
            ans.push_back(f);
        }
        
        return ans;
    }
};