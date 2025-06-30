/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void child_to_parent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>&mp, vector<TreeNode*>&leafNode){
        if(root == NULL) return ;
        if(!root->left && !root->right){
            leafNode.push_back(root);
        }
        
        if(root->left){
            mp[root->left] = root;
        }
        if(root->right){
            mp[root->right] = root;
        }
        child_to_parent(root->left, mp, leafNode);
        child_to_parent(root->right, mp, leafNode);
    }
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*, TreeNode*>mp;
        vector<TreeNode*>leafNode;

        child_to_parent(root, mp, leafNode);

        int count = 0;

        for(auto& leaf: leafNode){
            queue<TreeNode*>q;
            unordered_set<TreeNode*>st;
            q.push(leaf);
            int level = 0;
            st.insert(leaf);
            
            while(!q.empty()){
                int size = q.size();
                while(size--){
                    TreeNode*node = q.front();
                    q.pop();

                    if(!node->left && !node->right){
                        if(level != 0 && level <= distance){
                            count++;
                        }
                    }

                    if(node->left && st.find(node->left) == st.end()){
                        q.push(node->left);
                        st.insert(node->left);
                    } 
                    if(node->right && st.find(node->right) == st.end()){
                        q.push(node->right);
                        st.insert(node->right);
                    } 
                    if(mp.find(node) != mp.end() && st.find(mp[node]) == st.end()){
                        q.push(mp[node]);
                        st.insert(mp[node]);
                    }
                }
                level++;
                if(level > distance) break;
            }
        }
        return count/2;
    }
};






// class Solution {
// public:
//     int pairs = 0;
//     bool isLeaf(TreeNode* root) {
//         return !root->left && !root->right;
//     }
//     vector<int> findPairs(TreeNode* root, int distance, int depth) {
//         if(!root) return {};
//         if(isLeaf(root)) {
//             vector<int> dist;
//             dist.push_back(depth);
//             return dist;
//         }
//         vector<int> left_dist = findPairs(root->left, distance, depth + 1);
//         vector<int> right_dist = findPairs(root->right, distance, depth + 1);
//         for(int ld : left_dist) {
//             for(int rd : right_dist) {
//                 pairs += (ld + rd - (2 * depth) <= distance);
//             }
//         }
//         vector<int> res;
//         for(int ld : left_dist) res.push_back(ld);
//         for(int rd : right_dist) res.push_back(rd);
//         return res;
//     }
//     int countPairs(TreeNode* root, int distance) {
//         findPairs(root, distance, 0);
//         return pairs;
//     }
// };