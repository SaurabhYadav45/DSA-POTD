/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void child_to_parent_edge(TreeNode* root, unordered_map<TreeNode*, TreeNode*>&mp){
        if(root == NULL) return;
        if(root->left){
            mp[root->left] = root;
        }
        if(root->right){
            mp[root->right] = root;
        }
        child_to_parent_edge(root->left, mp);
        child_to_parent_edge(root->right, mp);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*>mp;
        child_to_parent_edge(root, mp);
        
        queue<TreeNode*>q;
        vector<bool>visited(500, false);
        q.push(target);
        visited[target->val] =true;
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            if(level == k){
                break;
            }
            while(size--){
                TreeNode* node = q.front();
                q.pop();
                if(node->left && visited[node->left->val] == false){
                    q.push(node->left);
                    visited[node->left->val] = true;
                }
                if(node->right && visited[node->right->val] == false){
                    q.push(node->right);
                    visited[node->right->val] = true;
                }
                if(mp.find(node) != mp.end() && visited[mp[node]->val] == false){
                    q.push(mp[node]);
                    visited[mp[node]->val] = true;
                }
            }
            level++;
        }

        vector<int>result;
        while(!q.empty()){
            result.push_back(q.front()->val);
            q.pop();
        }
        return result;
    }
};