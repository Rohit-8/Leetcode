class Solution {
public:
    
    vector<int> vis;
    map<int, bool> m;
    bool dfs(vector<vector<int>> &adj, int node){
        vis[node] = 1;
        bool f = true;
        
        for(auto x: adj[node]){
            if(vis[x] == 0){
                if(dfs(adj, x) == false)
                    f = false;
            }
            else f = f and m[x];
        }
        
        return m[node] = f;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n = adj.size();
        vis = vector<int> (n, 0);
        
        for(int i = 0; i < n; i++){
            if(vis[i] == 0)
                dfs(adj, i);
        }
        vector<int> ans;
        for(int i = 0; i < n; i++)
            if(m[i] == true)
                ans.push_back(i);
        
        return ans;
    }
};