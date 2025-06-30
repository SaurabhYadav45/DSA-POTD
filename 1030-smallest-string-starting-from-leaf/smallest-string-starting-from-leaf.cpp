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
    string result = "";
    void solve(TreeNode* root, string curr){
        if(root == NULL) return;
        curr = char(root->val + 'a') + curr; // O(length curr)
        if(root->left == NULL && root->right == NULL){
            if(result.empty() || curr < result){
                result = curr;
            }
        }
        solve(root->left, curr);
        solve(root->right, curr);
    }
    string smallestFromLeaf(TreeNode* root) {
        string curr;
        solve(root, curr);
        return result;
    }
};




// class Solution {
// public:
//     string solve(TreeNode* root){
//         if(root == NULL) return "";
//         string left = solve(root->left);
//         string right = solve(root->right);

//         int value = root->val;
//         char ch = value + 97;
        
//         if(left.empty()){
//             return right + ch;
//         }
//         if(right.empty()){
//             return left + ch;
//         }
//         return left + ch < right + ch ? left+ch : right+ch;
//     }
//     string smallestFromLeaf(TreeNode* root) {
//         return solve(root);
//     }
// };