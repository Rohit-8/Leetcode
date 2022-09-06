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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        bool f = false;
        
        while(!q.empty()){
            int n = q.size();
            vector<int> v;
            
            for(int i = 0; i < n; i++){
                TreeNode* t = q.front();
                q.pop();
                v.push_back(t -> val);
                
                if(t -> left) q.push(t -> left);
                if(t -> right) q.push(t -> right);
            }
            if(f)
                reverse(begin(v), end(v));
            
            f = !f;
            ans.push_back(v);
        }
        
        return ans;
    }
};