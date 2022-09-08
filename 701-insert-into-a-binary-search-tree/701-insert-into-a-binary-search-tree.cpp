class Solution {
public:
    TreeNode* res(TreeNode* root, int val){
        if(root == NULL) return NULL;
        
        if(root -> left == NULL and root -> right == NULL)
            return root;
        if(root -> val > val and root -> left == NULL)
            return root;
        if(root -> val < val and root -> right == NULL)
            return root;
        if(root -> val >  val)
            return res(root -> left , val);
        
        return res(root -> right, val);
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* t = new TreeNode(val);
        if(root == NULL) return t;
        
        TreeNode* x = res(root, val);
        
        if(x -> val >  val)
            x -> left = t;
        else x -> right = t;
        
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