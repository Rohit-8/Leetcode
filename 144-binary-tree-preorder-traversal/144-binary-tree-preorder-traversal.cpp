class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        while(root){
            if(root-> left == NULL){
                ans.push_back(root->val);
                root = root-> right;
            }
            else{
                TreeNode* temp = root->left;
                while(temp -> right and temp-> right != root)
                    temp = temp-> right;
                if(temp -> right == NULL){
                    temp->right = root;
                    ans.push_back(root->val);
                    root = root->left;
                }
                else{
                    root = root-> right;
                    temp -> right = NULL;
                }
            }
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