class Solution {
public:
    
    void res(TreeNode* root, int x, vector<TreeNode*> &v){
        if(root == NULL) return;
        v.push_back(root);
        if(root->val == x)
            return;
        
        if(root->val > x) res(root->left, x, v);
        else res(root->right, x, v);
        return;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == q or root == p) return root;
        
        if(root->val > min(p->val, q->val) and root->val < max(p->val, q->val)) return root;
        
        if(root->val > p->val) return lowestCommonAncestor(root->left, p, q);
        
        return lowestCommonAncestor(root->right, p, q);
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */