class Solution {
public:
    Node* res(Node* node, map<Node*, Node*> &m){
        if(node == NULL)
            return node;
        
        if(m.count(node)) return m[node];
        
        Node* t = new Node(node -> val);
        m[node] = t;
        vector<Node*> v;
        
        for(auto x: node -> neighbors){
            v.push_back(res(x, m));
        }
        
        t -> neighbors = v;
        return t;
    }
    
    Node* cloneGraph(Node* node) {
        map<Node*, Node*> m;
        return res(node, m);
    }
};
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/