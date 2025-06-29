class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int, int>child_to_parent;
        unordered_map<int, vector<int>>adj;
        for(int i=0; i<n; i++){
            int node  = i;
            int leftCh= leftChild[i];
            int rightCh = rightChild[i];
            if(leftCh != -1){
                adj[node].push_back(leftCh);
                if(child_to_parent.find(leftCh) != child_to_parent.end()){
                    return false;
                }
                else{
                    child_to_parent[leftCh] = node;
                }
            }

            if(rightCh != -1){
                adj[node].push_back(rightCh);
                if(child_to_parent.find(rightCh) != child_to_parent.end()){
                    return false;
                }
                else{
                    child_to_parent[rightCh] = node;
                }
            }
        }

        // Find root
        int root= -1;
        for(int i=0; i<n; i++){
            if(child_to_parent.find(i) == child_to_parent.end()){
                if(root != -1){
                    return false; // if more than one root exit 
                }
                root = i;
            }
        }
        if(root == -1){
            return false;
        }

        // check if the tree connected
        queue<int>q;
        q.push(root);
        int count = 1;
        while(!q.empty()){
            int p = q.front();
            q.pop();
            for(auto& v: adj[p]){
                count++;
                q.push(v);
            }
        }
        return count == n;
    }
};