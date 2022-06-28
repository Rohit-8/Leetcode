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
    int c = 0, k, ans = -1;;
    void inorder(TreeNode* root){
        if(root == NULL) return ;
        inorder(root->left);
        c++;
        if(c == k){
            ans = root->val;
            return;
        }
        inorder(root->right);
    }
    
    int kthSmallest(TreeNode* root, int x) {
        k = x;
        inorder(root);
        return ans;
    }
};