class Solution {
public:
    int camera = 0;
    int res(TreeNode* root){
        if(root==NULL) return 0;
        int lchild = res(root->left);
        int rchild = res(root->right);
        if(lchild == 1 or rchild==1){
            camera++;
            return -1;
        }
        if(lchild == -1 || rchild == -1) return 0;
        else return 1;
    }
    int minCameraCover(TreeNode* root) {
       if(res(root) == 1) {
           camera++;
       }
       return camera;
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