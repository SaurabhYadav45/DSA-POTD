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
    string findDuplicate(TreeNode* root, unordered_map<string, int>&mp, vector<TreeNode*>&result){
        if(root == NULL) return "N";

        string curr = to_string(root->val);
        string left = findDuplicate(root->left, mp, result);
        string right = findDuplicate(root->right, mp, result);
        string s = curr + "," + left + "," + right;

        if(mp.find(s) != mp.end()){
            if(mp[s] == 1){
                // to avoid multiple insertion of same subtree
                result.push_back(root);
            }
        }
        mp[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*>result;
        unordered_map<string, int>mp;
        findDuplicate(root, mp, result);
        return result;
    }
};





// class Solution {
// public:
//     vector<TreeNode*>ans;
//     unordered_map<string, int>subTreeMap;
//     string preorder(TreeNode* root){
//         if(root == NULL) return "N";
//         string curr = to_string(root->val);
//         string left = preorder(root->left);
//         string right = preorder(root->right);
//         string s = curr + "," + left + "," + right;
//         if(subTreeMap.find(s) != subTreeMap.end()){
//             if(subTreeMap[s] == 1){
//                 ans.push_back(root);
//             }
//             subTreeMap[s]++;
//         }
//         else{
//             subTreeMap[s] = 1;
//         }
//         return s;
//     }
//     vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
//         preorder(root);
//         return ans;
//     }
// };