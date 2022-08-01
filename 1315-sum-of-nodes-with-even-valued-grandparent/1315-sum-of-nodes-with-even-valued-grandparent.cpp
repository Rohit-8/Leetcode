class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        int ans = 0;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root, {1, 1}});
        
        
        while(!q.empty()){
            int par = q.front().second.first;
            int gp = q.front().second.second;
            TreeNode* x = q.front().first;
            
            q.pop();
            if(gp % 2 == 0){
                ans += x->val;
            }
            if(x->left) q.push({x->left, {x->val,par}});
            if(x->right) q.push({x->right, {x->val,par}});
            
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */