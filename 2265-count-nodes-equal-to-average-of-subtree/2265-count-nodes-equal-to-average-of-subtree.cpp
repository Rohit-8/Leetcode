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
    int ans = 0;
    vector<int> postorder(TreeNode* root){
        if(root == NULL)
            return {0, 0};
        vector<int> left = postorder(root -> left);
        vector<int> right = postorder(root -> right);
        
        int sum = left[0] + right[0] + root -> val;
        int l = left[1] + right[1] + 1;
        if(sum / l == root -> val)
            ans ++;
        
        return {sum, l};
    }
    
    int averageOfSubtree(TreeNode* root) {
        postorder(root);
        return ans;
    }
};