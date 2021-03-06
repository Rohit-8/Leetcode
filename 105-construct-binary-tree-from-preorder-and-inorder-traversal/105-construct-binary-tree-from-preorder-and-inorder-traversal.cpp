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
    map<int,int> m;
    
    TreeNode* res(vector<int> &pr, vector<int> &in, int ps, int pe, int ins, int ine){
        if(ps > pe or ins > ine) return NULL;
        
        TreeNode* root = new TreeNode(pr[ps]);
        int vl = m[root->val];
        int leftnode = vl - ins;
        
        root->left = res(pr, in, ps + 1, ps+leftnode, ins, ine-1);
        root->right = res(pr, in, ps + leftnode + 1, pe, vl + 1, ine);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& pr, vector<int>& in) {
        for(int i = 0; i < in.size(); i++)
            m[in[i]] = i;
        
        return res(pr, in, 0, pr.size()-1, 0, in.size()-1);
        
    }
};