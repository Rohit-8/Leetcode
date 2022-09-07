#define mod 1000000007
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        int l = INT_MAX;
        queue<pair<TreeNode*, long long>>q;
        q.push({root, 0});
        
        while(q.size()){
            int n = q.size(), r;
            int l = q.front().second;
            
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