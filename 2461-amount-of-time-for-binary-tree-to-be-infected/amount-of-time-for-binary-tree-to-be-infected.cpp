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
    void create_child_to_parent_edge(TreeNode*root, unordered_map<TreeNode*, TreeNode*>&mp){
        if(root == NULL) return ;
        if(root->left){
            mp[root->left] = root;
        }
        if(root->right){
            mp[root->right] = root;
        }
        create_child_to_parent_edge(root->left, mp);
        create_child_to_parent_edge(root->right, mp);
    }
    void findStartNode(TreeNode* root, int start, TreeNode*&target){
        if(root == NULL) return ;
        if(root->val == start){
            target = root;
            return;
        }
        findStartNode(root->left, start, target);
        findStartNode(root->right, start, target);
    }
    int amountOfTime(TreeNode* root, int start) {
        if(root->left == NULL && root->right == NULL){
            return 0;
        }
        // to keep track of child to parent edge
        unordered_map<TreeNode*, TreeNode*>mp;
        create_child_to_parent_edge(root, mp);
        TreeNode*target = NULL;
        findStartNode(root, start, target);

        queue<TreeNode*>q;
        unordered_set<int>st;
        q.push(target);
        st.insert(target->val);
        int time = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                TreeNode* node = q.front();
                q.pop();
                if(node->left && st.find(node->left->val) == st.end()){
                    q.push(node->left);
                    st.insert(node->left->val);
                }
                if(node->right && st.find(node->right->val) == st.end()){
                    q.push(node->right);
                    st.insert(node->right->val);
                }
                if(mp.find(node) != mp.end() && st.find(mp[node]->val) == st.end()){
                    q.push(mp[node]);
                    st.insert(mp[node]->val);
                }
            }
            time++;
        }
        return time-1;
    }
};