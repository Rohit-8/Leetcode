class Solution {
public:
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return root;
        if(root == p)
            return p;
        
        if(root == q)
            return q;
        
        TreeNode* left = lowestCommonAncestor(root -> left, p, q);
        TreeNode* right = lowestCommonAncestor(root -> right, p, q);
        
        if(left == p){
            if(right == q)
                return root;
        }
        if(right == p){
            if(left == q)
                return root;
        }
        
        if(left) return left;
        if(right) return right;
        return NULL;
    }
};
/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */