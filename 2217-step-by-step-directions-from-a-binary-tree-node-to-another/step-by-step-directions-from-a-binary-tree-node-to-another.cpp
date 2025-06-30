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
    TreeNode* findLCA(TreeNode* root, int startValue, int destValue){
        if(root == NULL) return NULL;
        if(root->val == startValue || root->val == destValue){
            return root;
        }
        TreeNode* l = findLCA(root->left, startValue, destValue);
        TreeNode* r = findLCA(root->right, startValue, destValue);
        if(l && r){
            return root;
        }
        return l ? l : r;
    }

    bool solve(TreeNode* LCA, int target, string& path){
        if(LCA == NULL) return false;

        if(LCA->val == target){
            return true;
        }

        path.push_back('L');
        bool l = solve(LCA->left, target, path);
        if(l == true){
            return true;
        }
        path.pop_back();
        
        path.push_back('R');
        bool r = solve(LCA->right, target, path);
        if(r == true) return true;
        path.pop_back();

        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* LCA = findLCA(root, startValue, destValue);
        string lca_to_src = "";
        string lca_to_dest = "";
        solve(LCA, startValue, lca_to_src);
        solve(LCA, destValue, lca_to_dest);

        string result = "";
        for(int i=0; i<lca_to_src.length(); i++){
            result.push_back('U');
        }
        result += lca_to_dest;
        return result;
    }
};









// class Solution {
//     void getPath(int value, TreeNode* root, string& path, bool& hasFound)
//     {
//         if(root == NULL)
//         {
//             return ;
//         }

//         if(root -> val == value)
//         {
//             hasFound = true ;
//             return ;
//         }

//         path.push_back('L') ;
//         getPath(value, root -> left, path, hasFound) ;

//         if(hasFound) return ;
//         path.pop_back() ;

//         path.push_back('R') ;
//         getPath(value, root -> right, path, hasFound) ;

//         if(hasFound) return ;
//         path.pop_back() ;
//     }
// public:
//     string getDirections(TreeNode* root, int startValue, int destValue) {
//         string path1 = "" ;
//         string path2 = "" ;
//         bool hasPath1Found = false ;
//         bool hasPath2Found = false ;

//         getPath(startValue, root, path1, hasPath1Found) ;
//         getPath(destValue, root, path2, hasPath2Found) ;

//         // cout << path1 << " " << path2 ;

//         while(path1[0] == path2[0])
//         {
//             path1.erase(0, 1);
//             path2.erase(0, 1);
//         }

//         // cout << '\n' ;
//         // cout << path1 << " " << path2 ;

//         for(int i=0; i<path1.length(); i++)
//         {
//             path1[i] = 'U' ;
//         }

//         return path1 + path2 ;
//     }
// };