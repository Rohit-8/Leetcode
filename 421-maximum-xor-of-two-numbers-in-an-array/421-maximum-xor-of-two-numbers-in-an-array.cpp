struct Node{
    Node* links[2];
    bool containsKey(int bit){
        return (links[bit] != NULL);
    }
    Node* get(int bit){
        return links[bit];
    }
    void put(int bit, Node* node){
        links[bit] = node;
    }
};

Node* root;
void insert(int a){
    Node* node = root;
    for(int i = 31; i >= 0; i--){
        int bit = ((a >> i) & 1);
        if(!node->containsKey(bit)){
            node->put(bit, new Node());
        }
        node = node-> get(bit);
    }
}

int find(int a){
    Node* node = root;
    int ans = 0;
    for(int i = 31; i >= 0; i--){
        int bit = ((a >> i) & 1);
        if(node->containsKey(1 - bit)){
            ans = ans | (1<<i);
            node = node->get(1 - bit);
        }
        else
            node = node->get(bit);
    }
    return ans;
}

class Solution {
public:
    int findMaximumXOR(vector<int>& a) {
        root = new Node();
        for(int i = 0; i < a.size(); i++){
            insert(a[i]);
        }
        int ans = 0;
        for(int i = 0; i < a.size(); i++){
            ans = max(ans, find(a[i]));
        }
        
        return ans;
    }
};