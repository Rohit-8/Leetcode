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
     void solve(vector<vector<int>> &ans, int targetSum, TreeNode* root, vector<int> &res, int sum){
         if(root == NULL){
             return;
         }
         sum += root -> val;
         res.push_back(root -> val);
         
         if(root -> left == NULL and root -> right == NULL){
             if(sum == targetSum)
                 ans.push_back(res);
             return ;
         }
         if(root -> left){
             solve(ans, targetSum, root -> left, res, sum);
             res.pop_back();
         }
         if(root -> right){
             solve(ans, targetSum, root -> right, res, sum);
             res.pop_back();
         }
         
     }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> res;
        solve(ans, targetSum, root, res, 0);
        return ans;
    }
};