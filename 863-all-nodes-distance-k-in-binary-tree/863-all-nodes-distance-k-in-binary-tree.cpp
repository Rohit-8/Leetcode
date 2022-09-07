class Solution {
public:
    map<TreeNode*, TreeNode*> m;
    void par(TreeNode* root){
        if(root == NULL) return;
        queue<TreeNode*> q;
        
        q.push(root);
        while(!q.empty()){
            TreeNode* t = q.front();
            q.pop();
            if(t -> left){
                m[t -> left] = t;
                q.push(t -> left);
            }
            if(t -> right){
                m[t -> right] = t;
                q.push(t -> right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* t, int k) {
        vector<int> ans;
        if(root == NULL) return ans;
        par(root);
        
        int c = -1;
        unordered_map<TreeNode*, int> vis;
        queue<TreeNode*> q;
        q.push(t);
        vis[t] = 1;
        
        while(!q.empty()){
            int n = q.size();
            c++;
            
            for(int i = 0; i < n; i++){
                TreeNode* x = q.front();
                q.pop();
                if(c == k){
                    // cout<<c <<" "<< x -> val<<" ";
                    ans.push_back(x -> val);
                    continue;
                }
                if(x -> left and vis[x -> left] <= 0)
                    q.push(x -> left), vis[x -> left] = 1;
                
                if(x -> right and vis[x -> right] <= 0)
                    q.push(x -> right), vis[x -> right] = 1;
                
                if(x != root and vis[m[x]] <= 0)
                    q.push(m[x]), vis[m[x]] = 1;
            }
            if(c >= k) break;
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