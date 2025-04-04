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


//                            Method-1;

// class Solution {
// public:
//     int maxDepth = 0;
//     unordered_map<int, int>mp;
//     TreeNode* solve(TreeNode*root){
//         if(root == NULL || mp[root->val] == maxDepth){
//             return root;
//         }

//         TreeNode* l = solve(root->left);
//         TreeNode* r = solve(root->right);

//         if(l && r){
//             return root;
//         }
//         return l != NULL ? l : r;
//     }
//     void calculateDepth(TreeNode*root, int depth){
//         if(root == NULL){
//             return;
//         }

//         maxDepth = max(maxDepth, depth);
//         mp[root->val] = depth;
//         calculateDepth(root->left, depth+1);
//         calculateDepth(root->right, depth+1);
//     }
//     TreeNode* lcaDeepestLeaves(TreeNode* root) {
//         calculateDepth(root, 0);

//         return solve(root);
//     }
// };


///                            Method-2

class Solution {
public:
    pair<int, TreeNode*>solve(TreeNode*root){
        if(root == NULL){
            return {0, NULL};
        }

        auto l = solve(root->left);
        auto r = solve(root->right);

        if(l.first ==  r.first){
            return {l.first+1, root};
        }
        else if(l.first > r.first){
            return{l.first+1, l.second};
        }
        else{
            return{r.first+1, r.second};
        }
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return solve(root).second;
    }
};