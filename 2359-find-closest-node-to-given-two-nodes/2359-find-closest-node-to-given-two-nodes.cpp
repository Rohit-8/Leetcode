class Solution {
public:
    unordered_map<int, int> m;
    int ans = -1;
    int x = INT_MAX;
    void res(vector<int> &a, int node, vector<int> &v, int c){
        if(node == -1) return;
        if(v[node]) return;
        v[node] = 1;
        
        if(m.count(node)){
            m[node] = max(m[node], c);
            if(m[node] < x){
                x = m[node];
                cout<<x<<endl;
                ans = node;
            }
            else if(m[node] == x and ans > -1){
                ans = min(ans, node);
            }
        }
        else m[node] = c;
        c++;
        
        res(a, a[node], v, c);
    }
    
    int closestMeetingNode(vector<int>& a, int node1, int node2) {
        vector<int> v1(a.size(), 0);
        
        int c = 0;
        res(a, node1, v1, c);
        for(int i = 0; i < a.size(); i++){
            v1[i] = 0;
        }
        c = 0;
        res(a, node2, v1, c);
        
        return ans;
    }
};