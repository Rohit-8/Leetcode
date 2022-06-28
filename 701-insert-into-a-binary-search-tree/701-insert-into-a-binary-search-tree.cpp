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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);
        TreeNode* t = root;
        
        while(t){
            if(t->val < val){
                if(t->right == NULL){
                    t->right = new TreeNode(val);
                    break;
                }
                else t = t->right;
            }
            else{
                if(t->left == NULL){
                    t->left = new TreeNode(val);
                    break;
                }
                else t = t->left;
            }
        }
        
        return root;
    }
};