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
    int widthOfBinaryTree(TreeNode* root) {
        
        int ans = 0, n, l = INT_MAX, r;
        queue<pair<TreeNode*, long long>>q;
        q.push({root, 0});
        
        while(q.size()){
            n = q.size();
            l = q.front().second;
            
            while(n--){
                auto [node, x] = q.front();
                q.pop();
                r = x;
                x = x - l;
                if(node->left) q.push({node->left, 2*x + 1});
                if(node->right) q.push({node->right, 2*x + 2});
            }
            ans = max(ans, (r-l)+1);
        }
        return ans;
    }
};