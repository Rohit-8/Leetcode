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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int x = 10000;
        
        int j = 0;
        while(!q.empty()){
            int n = q.size();
            j ++;
            if(j - x > 1){
                // cout << n <<" " << x << endl;
                return false;
            }
            bool r = false;
            
            for(int i = 0; i < n; i++){
                TreeNode* t = q.front();
                q.pop();
                if((t -> left == NULL or t -> right == NULL) and x == 10000)
                    x = j;
                
                if(t -> left and r)
                    return false;
                if(t -> left == NULL)
                    r = true;
                else q.push(t -> left);
                
                if(t -> right and r)
                    return false;
                if(t -> right)
                    q.push(t -> right);
                else r = true;
                
            }
        }
        // cout << x;
        return true;
    }
};