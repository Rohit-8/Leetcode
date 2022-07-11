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
    vector<int> ans;

    void traverse(TreeNode* root,int level){
        
        if(root == NULL) return ;
        
        if(level == ans.size()) ans.push_back(root->val);
        traverse(root->right, level+1);
        traverse(root->left, level+1);
        
    }
    
    vector<int> rightSideView(TreeNode* root) {
        // vector<int> ans;
//         if(root==NULL) return ans;
        
//         queue<TreeNode*> q;
//         q.push(root);
        
//         while(!q.empty()){
//             int n = q.size();
            
//             for(int i = 0; i< n;i++){
//                 TreeNode* t = q.front();
//                 q.pop();
                
//                 if( i == n-1) ans.push_back(t->val);
                
//                 if(t->left) q.push(t->left);
//                 if(t->right) q.push(t->right);
//             }
            
//         }
        
        traverse(root, 0);
        
        return ans;
        
    }
};