class Solution {
public:
    int ans = -1;
    int mn = INT_MAX;
    
    void res(vector<int> &a, int node, vector<int> &vis, vector<int> &d, int c){
        if(node == -1) return;
        if(vis[node]) return;
        vis[node] = 1;
        
        if(d[node] > -1){
            d[node] = max(d[node], c);
            if(d[node] < mn){
                mn = d[node];
                ans = node;
            }
            else if(d[node] == mn and ans > -1){
                ans = min(ans, node);
            }
        }
        else d[node] = c;
        c++;
        
        res(a, a[node], vis, d, c);
    }
    
    int closestMeetingNode(vector<int>& a, int node1, int node2) {
        vector<int> v1(a.size(), 0);
        vector<int> d(a.size(), -1);
        int c = 0;
        res(a, node1, v1, d, c);
        for(int i = 0; i < a.size(); i++){
            v1[i] = 0;
        }
        c = 0;
        res(a, node2, v1, d, c);
        
        return ans;
    }
};