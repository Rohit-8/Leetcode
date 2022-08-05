
class Solution {
public:
    
    Node* dfs( Node* curr, unordered_map<Node*, Node*>& m){
        
        Node* clone= new Node(curr->val);
        m[curr]=clone;
        for(auto &i:curr->neighbors){
            
            if(m.count(i)){
                clone->neighbors.push_back( m[i] );
            }
            else{
                clone->neighbors.push_back( dfs(i, m));
            }
        }
        return clone;
    }
    
    Node* cloneGraph(Node* node) {
     
        if(node == NULL) return NULL;
        
        unordered_map<Node*, Node*>m;
        return dfs( node, m);
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
