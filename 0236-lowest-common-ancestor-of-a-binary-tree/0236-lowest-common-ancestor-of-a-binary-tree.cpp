class Solution {
public:
    
    bool path(TreeNode* root,vector<TreeNode*> &ans, TreeNode* x){
        if(root == NULL) return false;
        
        ans.push_back(root);
        if(root == x) return true;
        
        if(path(root->left, ans, x) || path(root->right, ans, x))
            return true;
        
        ans.pop_back();
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v1, v2;
        path(root, v1,p);
        path(root, v2,q);
        
        TreeNode* ans;
        for(int i = 0; i< min(v1.size(), v2.size()); i++){
            if(v1[i] != v2[i]) break;
            ans = v1[i];
        }
        return ans;
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