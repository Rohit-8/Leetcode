class Solution {
public:
    
    TreeNode* createBinaryTree(vector<vector<int>>& a) {
        map<int, TreeNode*> mp;
        for(int i = 0; i < a.size(); i++){
            if(mp.count(a[i][0]) == false)
                mp[a[i][0]] = new TreeNode(a[i][0]);
            if(mp.count(a[i][1]) == false)
                mp[a[i][1]] = new TreeNode(a[i][1]);
        }
        TreeNode* root = NULL;
        map<int, int> par;
        
        for(int i = 0; i < a.size(); i++){
            if(a[i][2] == 1){
                mp[a[i][0]] -> left = mp[a[i][1]];
            }
            else mp[a[i][0]] -> right = mp[a[i][1]];
            par[a[i][1]] = a[i][0];
        }
        for(int i = 0; i < a.size(); i++){
            if(par[a[i][0]] <= 0){
                root = mp[a[i][0]];
                break;
            }
        }
        
        return root;
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