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
    
    TreeNode* build(vector<int> &a, int bound, int &i){
        if(i >= a.size() or a[i] >= bound) return NULL;
        
        TreeNode* root = new TreeNode(a[i++]);
        // i++;
        root->left = build(a, root->val, i);
        root->right = build(a, bound, i);
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& a) {
        int bound = INT_MAX;
        int i = 0;
        return build(a, bound, i);
    }
};