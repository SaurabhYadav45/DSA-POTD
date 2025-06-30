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
// class Solution {
// public:
//     bool isEvenOddTree(TreeNode* root) {
//         queue<TreeNode*>q;
//         q.push(root);
//         bool even = true;

//         while(!q.empty()){
//             int size = q.size();
//             int prev;
//             if(even == true){
//                 prev = INT_MIN;
//             }
//             else{
//                 prev = INT_MAX;
//             }
//             while(size--){
//                 TreeNode* node = q.front();
//                 q.pop();
//                 if(even){
//                     if(node->val % 2 == 0 || prev >= node->val){
//                         return false;
//                     }
//                 }
//                 else{
//                     if(node->val % 2 != 0 || prev <= node->val){
//                         return false;
//                     }
//                 }
//                 if(node->left){
//                     q.push(node->left);
//                 }
//                 if(node->right){
//                     q.push(node->right);
//                 }
//                 prev = node->val;
//             }
//             even = !even;
//         }
//         return true;
//     }
// };




//                 ******************  Using DFS **************************

class Solution {
public:
    bool solve(TreeNode* root, int level, vector<int>&levelPrev){
        if(root == NULL) return true;

        if(level % 2 == root->val % 2){
            return false;
        }

        if(level >= levelPrev.size()){
            levelPrev.resize(level+1);
        }

        if(levelPrev[level] != 0){
            if(level % 2 == 0 && levelPrev[level] >= root->val){
                return false;
            }
            if(level % 2 != 0 && levelPrev[level] <= root->val){
                return false;
            }
        }

        levelPrev[level] = root->val;
        
        bool l = solve(root->left, level+1, levelPrev);
        bool r = solve(root->right, level+1, levelPrev);
        return (l && r);
    }
    bool isEvenOddTree(TreeNode* root) {
        vector<int>levelPrev;
        return solve(root, 0, levelPrev);
    }
};