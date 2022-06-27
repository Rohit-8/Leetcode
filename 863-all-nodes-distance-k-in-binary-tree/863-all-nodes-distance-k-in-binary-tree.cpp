class Solution {
public:
    map<TreeNode*, TreeNode*> m;
    
    void par(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root); 
        m[root] = NULL;
        
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                TreeNode* x = q.front();
                q.pop();
                if(x->left){
                    m[x->left] = x;
                    q.push(x->left);
                }
                if(x->right){
                    m[x->right] = x;
                    q.push(x->right);
                }
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* t, int k) {
        vector<int> ans;
        
        if(k == 0){
            ans.push_back(t->val);
            return ans;
        }
        vector<int> vis(501, 0);
        par(root);
        int c = -1;
        // cout<<m[root->left]->val;
        queue<TreeNode*> q;
        q.push(t);
        vis[t->val] = 1;
        
        while(!q.empty()){
            
            int n = q.size();
            c++;
            if(c > k) break;
            for(int i = 0; i < n; i++){
                TreeNode* x = q.front(); q.pop();
                
                if(c == k) ans.push_back(x->val);
                
                if(x->left and vis[x->left->val] == 0) 
                    q.push(x->left);
                if(x->right and vis[x->right->val] == 0)
                    q.push(x->right);
                // cout<<c;
                if(m[x] and vis[m[x]->val] == 0)
                    q.push(m[x]);
                
                vis[x->val] = 1;
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */