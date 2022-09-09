class Solution {
public:
    int lh(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + lh(root -> left);
    }
    int rh(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + rh(root -> right);
    }
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int sum = 0;
        int l = lh(root -> left);
        int r = rh(root -> right);
        
        if(l == r) return (1<<l) + (1<<r) - 1;
        
        return 1 + countNodes(root -> left) + countNodes(root -> right);
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