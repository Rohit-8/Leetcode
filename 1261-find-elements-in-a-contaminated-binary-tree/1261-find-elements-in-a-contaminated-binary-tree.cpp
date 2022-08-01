class FindElements {
public:
    unordered_map<int,int> m;
    
    void res(TreeNode* root, int i){
        if(root == NULL) return;
        m[i]++;
        res(root->left, 2*i + 1);
        res(root->right, 2*i + 2);
    }
    FindElements(TreeNode* root) {
        res(root, 0);
    }
    
    bool find(int target) {
        if(m.find(target) == m.end()) return false;
        return true;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */

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