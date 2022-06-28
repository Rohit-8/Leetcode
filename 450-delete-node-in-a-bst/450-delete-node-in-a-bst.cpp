class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* dummy = new TreeNode(0);
        dummy ->right = root;
        TreeNode* prev = dummy;
        
        bool f = 1;
        while(root){
            if(root->val == key and root->right == NULL){
                if(f)
                prev ->right = root->left;
                else prev->left = root->left;
                break;
            }
            if(root->val == key and root->right){
                TreeNode* le = root->left;
                TreeNode* ri = root->right;
                
                if(f) prev ->right = ri;
                else prev->left = ri;
                
                while(ri->left)
                    ri = ri->left;
                
                ri->left = le;
                break;
            }
            if(root->val > key){
                prev = root;
                root = root->left;
                f = 0;
            }
            else{
                prev = root;
                root = root->right;
                f = 1;
            }
        }
        return dummy->right;
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