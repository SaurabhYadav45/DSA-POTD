class Solution {
public:
    void wiggleSort(vector<int>& v) {
        int n=v.size();
        sort(v.begin(),v.end());
        deque<int> dq;
        for(auto it: v) dq.push_back(it);
        int i=0;
    //  while(!dq.empty()){
           for(i=1;i<n;i+=2){
                v[i]=dq.back();
                dq.pop_back();
            }
            for(i=0;i<n;i+=2){
                v[i]=dq.back();
                dq.pop_back();
            }
        
        // return v;
    }
};