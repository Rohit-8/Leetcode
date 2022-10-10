/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void res(Node* root, vector<int> & ans) {
        if(root == NULL) return;
        
        for(auto x: root -> children) {
            res(x, ans);
        }
        
        ans.push_back(root -> val);
        return;
    }
    
    vector<int> postorder(Node* root) {
        vector<int> ans;
        res(root, ans);
        
        return ans;
    }
};