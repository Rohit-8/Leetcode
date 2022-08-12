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
        TreeNode* ans;
        vector<TreeNode*> v1, v2;
        res(root, p->val, v1);
        res(root, q->val, v2);
        
        for(int i = 0; i < min(v1.size(), v2.size()); i++){
            if(v1[i] != v2[i]) break;
            ans = v1[i];
        }
        
        return ans;
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