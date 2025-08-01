class Solution {
public:
    bool isPrime(int x) {
        if (x <= 1) return false;
        if (x <= 3) return true;
        if (x % 2 == 0) return false;
        for (int i = 3; i * i <= x; i += 2) {
            if (x % i == 0) return false;
        }
        return true;
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> valueToIndex;
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            valueToIndex[nums[i]].push_back(i);
            maxi = max(maxi, nums[i]);
        }

        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        queue<int> q;
        q.push(0);

        unordered_set<int> usedPrimeVal; // visited prime values

        while (!q.empty()) {
            int currIdx = q.front();
            q.pop();

            // Move left
            if (currIdx - 1 >= 0 && dist[currIdx - 1] == INT_MAX) {
                dist[currIdx - 1] = dist[currIdx] + 1;
                if (currIdx - 1 == n - 1) return dist[currIdx - 1];
                q.push(currIdx - 1);
            }

            // Move right
            if (currIdx + 1 < n && dist[currIdx + 1] == INT_MAX) {
                dist[currIdx + 1] = dist[currIdx] + 1;
                if (currIdx + 1 == n - 1) return dist[currIdx + 1];
                q.push(currIdx + 1);
            }

            // Prime teleport
            if (!isPrime(nums[currIdx]) || usedPrimeVal.count(nums[currIdx])) continue;

            for (long long mul = nums[currIdx]; mul <= maxi; mul += nums[currIdx]) {
                if (valueToIndex.count(mul)) {
                    for (int newIdx : valueToIndex[mul]) {
                        if (dist[newIdx] == INT_MAX) {
                            dist[newIdx] = dist[currIdx] + 1;
                            if (newIdx == n - 1) return dist[newIdx];
                            q.push(newIdx);
                        }
                    }
                }
            }
            usedPrimeVal.insert(nums[currIdx]);
        }
        return dist[n - 1];
    }
};




// class Solution {
// public:
//     bool isPrime(int x){
//         if(x <= 1) return false;
//         if(x == 2 || x == 3) return true; 
//         if(x % 2 == 0) return  false;
//         for(int i=3; i*i <= x; i += 2){
//             if(x % i == 0) return false;
//         }
//         return true;
//     }
//     int minJumps(vector<int>& nums) {
//         int n = nums.size();
//         unordered_map<int, vector<int>>valueToIndex;
//         int maxi = 0;
//         for(int i=0; i<n; i++){
//             valueToIndex[nums[i]].push_back(i);
//             maxi = max(maxi,  nums[i]);
//         }

//         unordered_set<int>st; // Visited array
//         vector<int>dist(n, INT_MAX);
//         queue<int>q;
//         q.push(0);
//         dist[0] = 0;

//         while(!q.empty()){
//             int currIdx = q.front();
//             q.pop();

//             if(currIdx-1 >= 0 && dist[currIdx-1] == INT_MAX){
//                 q.push(currIdx-1);
//                 dist[currIdx-1] = dist[currIdx] + 1;
//             }

//             if(currIdx+1 < n && dist[currIdx+1] == INT_MAX){
//                 q.push(currIdx+1);
//                 dist[currIdx+1] = dist[currIdx] + 1;
//             }

//             // Jump via prime teleportation
//             if(isPrime(nums[currIdx]) == false || st.count(nums[currIdx])){
//                 continue;
//             }

//             long long i=1;
//             while(true){
//                 long long new_node_val = (long long)nums[currIdx]*i;
//                 if(new_node_val > maxi){
//                     break;
//                 }
                
//                 if(valueToIndex.count(new_node_val)){
//                     for(auto& new_node_idx: valueToIndex[new_node_val]){
//                         if(dist[new_node_idx] == INT_MAX){
//                             q.push(new_node_idx);
//                             dist[new_node_idx] = dist[currIdx]+1;
//                         }
//                     }
//                 }
//                 i++;
//             }
//             st.insert(nums[currIdx]);

//             if(dist[n-1] != INT_MAX) break;
//         }
//         return dist[n-1];
//     }
// };




// class Solution {
// public:
//     bool isPrime(int x){
//         if(x <= 1) return false;
//         if(x == 2 || x == 3) return true; 
//         if(x % 2 == 0) return  false;
//         for(int i=3; i*i <= x; i += 2){
//             if(x % i == 0) return false;
//         }
//         return true;
//     }
//     int minJumps(vector<int>& nums) {
//         int n = nums.size();
//         unordered_map<int, vector<int>>mp;
//         for(int i=0; i<n; i++){
//             mp[nums[i]].push_back(i);
//         }

//         unordered_map<int, vector<int>>adj;
//         unordered_set<int>st;
//         for(int i=0; i<n; i++){
//             int num = nums[i];
//             int t = num;
//             for(int p=2; p*p <= t; p++){
//                 if(num%p == 0){
//                     if(isPrime(p)){
//                         adj[p].push_back(i);
//                     }
//                     while(num % p == 0) num /= p;
//                 }
//             }
//             if(num > 1 && isPrime(num)){
//                 adj[num].push_back(i);
//             }
//         }

//         queue<int>q;
//         vector<bool>visited(n, false);
//         q.push(0);
//         visited[0] = true;
//         int count = 0;
//         while(!q.empty()){
//             int size = q.size();
//             while(size--){
//                 int i = q.front();
//                 q.pop();

//                 if(i == n-1) return count;
//                 if(i+1 < n && !visited[i+1]){
//                     visited[i+1]= true;
//                     q.push(i+1);
//                 }
//                 if(i-1 >= 0 && !visited[i-1]){
//                     visited[i-1] = true;
//                     q.push(i - 1);
//                 }

//                 int val = nums[i];
//                 if(isPrime(val) && st.find(val) == st.end()){
//                     for(int j: adj[val]){
//                         if(j != i && !visited[j]){
//                             visited[j] = true;
//                             q.push(j);
//                         }
//                     }
//                     st.insert(val);
//                 }
//             }
//             count++;
//         }
//         return -1;
//     }
// };