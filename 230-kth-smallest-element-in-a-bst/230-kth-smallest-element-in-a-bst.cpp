class Solution {
public:
    priority_queue<int> p;
    void res(TreeNode* root, int k){
        if(root == NULL)
            return;
        p.push(root -> val);
        if(p.size() > k)
            p.pop();
        
        res(root -> left, k);
        res(root -> right, k);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        res(root, k);
        return p.top();
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