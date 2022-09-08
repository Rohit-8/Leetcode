class Solution {
public:
    TreeNode* p = NULL;
    TreeNode* sr(TreeNode* root, int val, TreeNode* par){
        if(root == NULL) return NULL;
        if(root -> val == val) {
            p = par;
            return root;
        }
        if(root -> val > val) return sr(root -> left, val, root);
        return sr(root -> right, val, root);
    }
    
    TreeNode* res(TreeNode* root){
        if(root == NULL) return root;
        if(root -> right == NULL) return root;
        return res(root -> right);
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;
        TreeNode* t = root;
        TreeNode* x = sr(root, key, NULL);
        if(x == NULL) return root;
        TreeNode* l = res(x -> left);
        
        if(!p){
            if(!l)
                return root -> right;
            l -> right = x -> right;
            return root -> left;
        }
        if(p -> val > key){
            if(!l)
                p -> left = x -> right;
            else{
                p -> left = x -> left;
                l -> right = x -> right;
            }
        }
        else {
            if(!l)
                p -> right = x -> right;
            else{
                p -> right = x -> left;
                l -> right = x -> right;
            }
        }
        
        return root;
    }
};
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