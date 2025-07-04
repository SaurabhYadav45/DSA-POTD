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
    int maxPath = -1;
    void findLongesZingZaga(TreeNode*root, int steps, bool goLeft){
        if(root == NULL) return;
        maxPath = max(maxPath, steps);
        if(goLeft){
            findLongesZingZaga(root->right, steps+1, false);
            findLongesZingZaga(root->left, 1, true); // Explore New path
        }
        else{
            findLongesZingZaga(root->left, steps+1, true);
            findLongesZingZaga(root->right, 1, false);  // Explore New path
        }
    }
    int longestZigZag(TreeNode* root) {
        findLongesZingZaga(root, 0, true);
        findLongesZingZaga(root, 0, false);
        return maxPath;
    }
};


// class Solution {
// public:
//     int maxPath = -1;
//     void findLongesZingZaga(TreeNode*root, int left, int right){
//         if(root == NULL) return;

//         maxPath = max({maxPath, left, right});
//         findLongesZingZaga(root->left, right+1, 0);
//         findLongesZingZaga(root->right, 0, left+1);
//     }
//     int longestZigZag(TreeNode* root) {
//         findLongesZingZaga(root, 0, 0);
//         return maxPath;
//     }
// };