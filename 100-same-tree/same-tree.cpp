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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;

        if(p != NULL && q !=  NULL){
            if((p->val == q->val) &&
            isSameTree(p->left, q->left) &&
            isSameTree(p->right, q->right)){
                return true;
            }
        }
        return false;
    }
};




// class Solution {
// public:
//     void solve(TreeNode*root, string& s){
//         if(root == NULL){
//             s.push_back('#');
//             return;
//         }
//         s.push_back(root->val);
//         solve(root->left, s);
//         solve(root->right, s);
//     }
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         string s1;
//         string s2;
//         solve(p, s1);
//         solve(q, s2);
//         if(s1 == s2) return true;
//         return false;
//     }
// };




// class Solution {
// public:
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         if(p == NULL && q == NULL) return true;

//         if(p != NULL && q != NULL){
//             return (p->val == q->val)
//             && isSameTree(p->left, q->left)
//             && isSameTree(p->right, q->right);
//         }
//         return false;
//     }
// };