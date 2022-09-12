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
    int getMinimumDifference(TreeNode* root) {
        TreeNode* curr = root ;
        
        stack<TreeNode*> st ;
        
        int last = -1e9 ;
        
        int mn = 1e9 ;
        
        while(curr)
        {
            st.push(curr) ;
            curr = curr->left ;
        }
        
        while(st.size()>0)
        {
            curr = st.top() ;
            mn = min(mn,abs(last-curr->val)) ;
            st.pop() ;
            last = curr->val ;
            
            curr = curr->right ;
            
            while(curr)
            {
                st.push(curr) ;
                curr = curr->left ;
            }
        }
        
        return mn ;
    }
};