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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> morris;
        TreeNode* cur = root;
        
        while(cur != NULL){
            if(cur ->left == NULL){
                morris.push_back(cur->val);
                cur = cur->right;
            }
            else{
                TreeNode* pre = cur->left;
                while(pre->right and pre->right != cur){
                    pre = pre->right;
                }
                if(pre->right == NULL){
                    pre->right = cur;
                    morris.push_back(cur->val);
                    cur = cur->left;
                }
                else{
                    pre->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return morris;
    }
};