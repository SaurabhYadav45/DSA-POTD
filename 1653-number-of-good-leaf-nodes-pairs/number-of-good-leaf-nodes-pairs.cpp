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
//             *********************** Using BFS ***********************

// class Solution {
// public:
//     void createGraph(TreeNode* root, TreeNode*prev, unordered_map<TreeNode*, vector<TreeNode*>>&adj, unordered_set<TreeNode*>&leafNode){
//         if(root == NULL) return ;
//         if(!root->left && !root->right){
//             leafNode.insert(root);
//         }
        
//         if(prev != NULL){
//             adj[prev].push_back(root);
//             adj[root].push_back(prev);
//         }
//         createGraph(root->left, root, adj, leafNode);
//         createGraph(root->right,root, adj, leafNode);
//     }
//     int countPairs(TreeNode* root, int distance) {
//         unordered_map<TreeNode*, vector<TreeNode*>>adj;
//         unordered_set<TreeNode*>leafNode;

//         createGraph(root,NULL, adj, leafNode);

//         int count = 0;

//         for(auto& leaf: leafNode){
//             queue<TreeNode*>q;
//             unordered_set<TreeNode*>st;
//             q.push(leaf);
//             st.insert(leaf);
            
//             for(int level=0; level<=distance; level++){
//                 int size = q.size();
//                 while(size--){
//                     TreeNode*node = q.front();
//                     q.pop();

//                     if(node != leaf && leafNode.count(node)){
//                         count++;
//                     }
//                     for(auto& nbr : adj[node]){
//                         if(!st.count(nbr)){
//                             q.push(nbr);
//                             st.insert(nbr);
//                         }
//                     }
//                 }
//             }
//         }
//         return count/2;
//     }
// };


//             *********************** Using BFS ***********************

class Solution {
public:
    vector<int>solve(TreeNode* root, int distance, int& goodCount){
        if(root == NULL) return {0};

        if(root->left == NULL && root->right == NULL){
            return {1};
        }

        vector<int>left = solve(root->left, distance, goodCount);
        vector<int>right = solve(root->right, distance, goodCount);

        for(int& l : left){
            for(int& r: right){
                if(l != 0 && r != 0 && l + r <= distance){
                    goodCount++;
                }
            }
        }

        vector<int>goodPath;
        for(int& l : left){
            if(l != 0 && l + 1 <= distance){
                goodPath.push_back(l+1);
            }
        }

        for(int& r : right){
            if(r != 0 && r + 1 <= distance){
                goodPath.push_back(r+1);
            }
        }

        return goodPath;
    }
    int countPairs(TreeNode* root, int distance) {
        int goodCount = 0;
        solve(root, distance, goodCount);
        return goodCount;
    }
};




// class Solution {
// public:
//     void child_to_parent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>&mp, vector<TreeNode*>&leafNode){
//         if(root == NULL) return ;
//         if(!root->left && !root->right){
//             leafNode.push_back(root);
//         }
        
//         if(root->left){
//             mp[root->left] = root;
//         }
//         if(root->right){
//             mp[root->right] = root;
//         }
//         child_to_parent(root->left, mp, leafNode);
//         child_to_parent(root->right, mp, leafNode);
//     }
//     int countPairs(TreeNode* root, int distance) {
//         unordered_map<TreeNode*, TreeNode*>mp;
//         vector<TreeNode*>leafNode;

//         child_to_parent(root, mp, leafNode);

//         int count = 0;

//         for(auto& leaf: leafNode){
//             queue<TreeNode*>q;
//             unordered_set<TreeNode*>st;
//             q.push(leaf);
//             int level = 0;
//             st.insert(leaf);
            
//             while(!q.empty()){
//                 int size = q.size();
//                 while(size--){
//                     TreeNode*node = q.front();
//                     q.pop();

//                     if(!node->left && !node->right){
//                         if(level != 0 && level <= distance){
//                             count++;
//                         }
//                     }

//                     if(node->left && st.find(node->left) == st.end()){
//                         q.push(node->left);
//                         st.insert(node->left);
//                     } 
//                     if(node->right && st.find(node->right) == st.end()){
//                         q.push(node->right);
//                         st.insert(node->right);
//                     } 
//                     if(mp.find(node) != mp.end() && st.find(mp[node]) == st.end()){
//                         q.push(mp[node]);
//                         st.insert(mp[node]);
//                     }
//                 }
//                 level++;
//                 if(level > distance) break;
//             }
//         }
//         return count/2;
//     }
// };