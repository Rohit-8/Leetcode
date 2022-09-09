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
    
    bool check(TreeNode* root, long int l, long int r){
        if(root == NULL) return true;
        if(root -> val <= l or root -> val >= r)
            return false;
        return check(root -> left, l, root -> val) and check(root -> right, root -> val, r);
    }
    
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        return check(root -> left, (long int)INT_MIN-1, root -> val) and check(root -> right, root -> val, (long int)INT_MAX + 1);
    }
};