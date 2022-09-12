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
    int mn = 1e9;
    
    void res(TreeNode* root, int &last){
        if(root == NULL) return;
        
        res(root -> left, last);
        mn = min(mn, abs(last - root -> val));
        last = root -> val;
        res(root -> right, last);
    }
    
    int getMinimumDifference(TreeNode* root) {
        int last = -1e9;
        res(root, last);
        return mn;
    }
};