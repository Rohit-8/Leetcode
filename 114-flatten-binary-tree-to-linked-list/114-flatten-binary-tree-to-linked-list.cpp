class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* t = root;
        
        while(t){
            if(t->left == NULL){
                t = t->right;
                continue;
            }
            
            TreeNode* next = t->right;
            TreeNode* x = t->left;
            t->right = x;
            while(x->right){
                x = x->right;
            }
            
            x->right = next;
            t->left = NULL;
            t = t->right;
        }
        return;
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
