class Solution {
public:
    int d = 0;
    int height(TreeNode* root){
        if(root == NULL) return 0;
        
        int left = height(root -> left);
        int right = height(root -> right);
        
        d = max(left + right, d);
        return max(left, right) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        height(root);
        
        return d;
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