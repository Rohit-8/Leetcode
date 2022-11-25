class Solution {
public:
    int ans = INT_MIN;
    int res(TreeNode* root){
        if(root == NULL) return 0;
        
        int left = res(root -> left);
        int right = res(root -> right);
        
        ans = max({ans, left + right + root -> val, left + root -> val, right + root->val, root->val});
        
        return max({left + root->val, right + root->val, root->val});
    }
    
    int maxPathSum(TreeNode* root) {
        if(root == NULL) return 0;
        res(root);
        return ans;
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