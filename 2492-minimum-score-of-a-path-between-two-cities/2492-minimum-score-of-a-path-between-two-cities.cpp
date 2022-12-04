class Solution {
public:
    int ans = INT_MAX;
    
    void res(vector<vector<pair<int, int>>> &adj, int node, vector<int> &vis){
        vis[node] = 1;
        
        for(auto x: adj[node]){
            ans = min(ans, x.second);
            if(vis[x.first] == 0){  
                res(adj, x.first, vis);
            }
        }
    }
    
    int minScore(int n, vector<vector<int>>& a) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for(int i = 0; i < a.size(); i++){
            adj[a[i][0]].push_back({a[i][1], a[i][2]});
            adj[a[i][1]].push_back({a[i][0], a[i][2]});
        }
        vector<int> vis(n + 1, 0);
        res(adj, 1, vis);
        
        return ans;
    }
};