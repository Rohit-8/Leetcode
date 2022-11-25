class Solution {
public:
    int res(TreeNode* root, int &ans){
        if(root == NULL) return 0;
        
        int x = root -> val;
        int left = res(root -> left, ans);
        int right = res(root -> right, ans);
        ans = max({ans, x, x + left, x + right, x + left + right});
        return max({x, x + left, x + right});
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        res(root, ans);
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