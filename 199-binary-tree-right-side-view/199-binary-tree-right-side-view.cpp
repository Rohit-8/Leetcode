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
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> rst;
        queue<TreeNode *> pre;
        if(NULL != root) pre.push(root) ;
        while(!pre.empty()){
            
            rst.push_back(pre.front()->val);
            queue<TreeNode *> cur;
            
            while(!pre.empty()){
                
                TreeNode * node = pre.front();
                
                pre.pop();
                
                if(NULL != node->right) cur.push(node->right);
                if(NULL != node->left)  cur.push(node->left);
            }
            pre.swap(cur);
        }
        
        return rst;
        
    }
};