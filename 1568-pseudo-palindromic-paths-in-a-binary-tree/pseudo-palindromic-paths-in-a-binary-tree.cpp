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

//                    ****************** Optimized ***********

// class Solution {
// public:
//     bool checkPalindrome(vector<int>&currFreq){
//         int oddCount = 0;
//         for(int i=1; i<=9; i++){
//             if(currFreq[i] == 0) continue;
//             if(currFreq[i] % 2 != 0){
//                 oddCount++;
//             }
//         }
//         if(oddCount > 1){
//             return false;
//         }
//         return true;
//     }
//     void solve(TreeNode* root, vector<int>&currFreq, int& result){
//         if(root == NULL) return ;

//         currFreq[root->val]++;
//         if(root->left == NULL && root->right == NULL){
//             if(checkPalindrome(currFreq)){
//                 result++;
//             }
//         }
//         solve(root->left, currFreq, result);
//         solve(root->right, currFreq, result);
//         // Backtrack
//         currFreq[root->val]--;
//     }
//     int pseudoPalindromicPaths (TreeNode* root) {
//         vector<int>currFreq(10, 0);
//         int result = 0;
//         solve(root, currFreq, result);
//         return result;
//     }
// };


//                     ***************** BitMasking ****************

class Solution {
public:
    void solve(TreeNode* root, int count, int& result){
        if(root == NULL) return ;

        count ^= (1 << root->val);
        if(root->left == NULL && root->right == NULL){
            if((count & (count-1)) == 0){
                result++;
            }
            return;
        }
        solve(root->left, count, result);
        solve(root->right, count, result);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int result = 0;
        int count = 0;
        solve(root, count, result);
        return result;
    }
};



//                           ****** Brute Force *********

// class Solution {
// public:
//     bool checkPalindrome(vector<int>&curr){
//         int n = curr.size();
//         vector<int>freq(10, 0);
//         for(int i=0; i<n; i++){
//             freq[curr[i]]++;
//         }

//         int oddCount = 0;
//         for(int i=1; i<=9; i++){
//             if(freq[i] == 0) continue;
//             if(freq[i] % 2 != 0){
//                 oddCount++;
//             }
//         }
//         if(oddCount > 1){
//             return false;
//         }
//         return true;
//     }
//     void solve(TreeNode* root, vector<int>&curr, int& result){
//         if(root == NULL) return ;

//         curr.push_back(root->val);
//         if(root->left == NULL && root->right == NULL){
//             if(checkPalindrome(curr)){
//                 result++;
//             }
//         }
//         solve(root->left, curr, result);
//         solve(root->right, curr, result);
//         curr.pop_back();
//     }
//     int pseudoPalindromicPaths (TreeNode* root) {
//         vector<int>curr;
//         int result = 0;
//         solve(root, curr, result);
//         return result;
//     }
// };