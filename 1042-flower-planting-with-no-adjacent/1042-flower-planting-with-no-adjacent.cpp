class Solution {
public:
    
    vector<int> vis;
    vector<vector<int>> adj;
    unordered_map<int,int> m;
    
    void dfs(int node){
        vis[node] = 1;
        
        for(auto x: adj[node]){
            if(vis[x] == 0){
                for(int i = 1; i < 5; i++){
                    bool f = true;
                    
                    for(auto c: adj[x])
                        if(vis[c] == 1 and m[c] == i) f = false;
                    
                    if(f){
                        m[x] = i; break;
                    }
                }
                dfs(x);
            }
        }
    }
    
    vector<int> gardenNoAdj(int n, vector<vector<int>>& a) {
        
        vis.resize(n + 1, 0);
        adj.resize(n + 1);
        for(int i = 0; i < a.size(); i++){
            adj[a[i][0]].push_back(a[i][1]);
            adj[a[i][1]].push_back(a[i][0]);
        }
        
        for(int i = 1; i <= n; i++){
            if(vis[i] == 0)
                m[i] = 1, dfs(i);
        }
        
        vector<int> ans;
        for(int i = 1; i <= n; i++)
            ans.push_back(m[i]);
        
        return ans;
    }
};