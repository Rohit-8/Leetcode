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
    
    bool check(TreeNode* root, long long mn, long long mx){
        if(root==NULL) return true;
        
        return (root->val >mn) and (root->val < mx) and check(root->left, mn, root->val) && check(root->right, root->val, mx);
    }
    
    
    bool isValidBST(TreeNode* root) {
        
        // inorder(root);
        // for(int i =1; i<v.size();i++){
        //     if(v[i]<=v[i-1]) return false;
        // }
        long long mn = LONG_MIN, mx = LONG_MAX;
        return check(root, mn, mx);
        
    }
};