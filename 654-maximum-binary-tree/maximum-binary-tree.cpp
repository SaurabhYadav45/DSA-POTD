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
    TreeNode* solve(vector<int>& nums, int start, int end){
        // Base case
        if(start > end) return NULL;

        int maxIdx = start;
        for(int i=start+1; i<=end; i++){
            if (nums[i] > nums[maxIdx]) {
                maxIdx = i;
            }
        }

        TreeNode* root = new TreeNode(nums[maxIdx]);
        root->left = solve(nums, start, maxIdx-1);
        root->right = solve(nums, maxIdx+1, end);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n-1;
        return solve(nums, start, end);
    }
};