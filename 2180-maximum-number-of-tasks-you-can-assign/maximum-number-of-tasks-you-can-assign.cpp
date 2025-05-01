class Solution {
public:
    bool check(vector<int>& tasks, vector<int>& workers, int pills, int strength, int mid){
        int pillsUsed = 0;
        multiset<int>st(workers.begin(), workers.begin()+ mid);

        for(int i=mid-1; i>=0; i--){
            int task = tasks[i];
            auto it = prev(st.end());
            if(*it >= task){
                st.erase(it);
            }
            else if(pillsUsed >= pills){
                return false;
            }
            else{
                auto weakestWorkerIt = st.lower_bound(task-strength);
                if(weakestWorkerIt == st.end()){
                    return false;
                }
                st.erase(weakestWorkerIt);
                pillsUsed++;
            }
        }
        return true;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int m = tasks.size();
        int n = workers.size();
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end(), greater<int>());

        int result = 0;
        int l = 0;
        int r = min(m, n);

        while(l <= r){
            int mid = l + (r-l)/2;
            if(check(tasks, workers, pills, strength, mid)){
                result = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return result;
    }
};




// class Solution {
// public:
//     int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
//         sort(tasks.begin(), tasks.end());
//         sort(workers.begin(), workers.end());

//         int count = 0;

//         int i=0, j=0;
//         while(i < tasks.size() && j < workers.size()){
//             int task = tasks[i];
//             int worker = workers[j];

//             if(worker >= task){
//                 count++;
//                 i++;
//             }
//             else if( pills > 0 && worker + strength >= task){
//                 count++;
//                 pills--;
//                 i++;
//             }
//             j++;
//         }
//         return count;
//     }
// };