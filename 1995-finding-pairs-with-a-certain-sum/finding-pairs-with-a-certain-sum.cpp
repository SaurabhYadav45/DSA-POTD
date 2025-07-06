class FindSumPairs {
public:
    vector<int>arr1;
    vector<int>arr2;
    unordered_map<int, int>mp1, mp2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        arr1 = nums1;
        arr2 = nums2;
        for(int& num : arr1) mp1[num]++;
        for(int& num : arr2) mp2[num]++;
    }
    
    void add(int index, int val) {
        int oldValue = arr2[index];
        mp2[oldValue]--;
        if(mp2[oldValue] == 0) mp2.erase(oldValue);
        int newValue = oldValue + val;
        mp2[newValue]++;
        arr2[index] = newValue;
    }
    
    int count(int tot) {
        int pairs = 0;
        for(auto& it: mp1){
            int num = it.first;
            int cnt = it.second;
            int rem = tot - num;
            if(mp2.find(rem) != mp2.end()){
                pairs += mp2[rem]*cnt;
            }
        }
        return pairs;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */