class Solution {
public:
    vector<vector<int>> adj;
    vector<int> vis;
    map<int,set<int>> m;
    
    void dfs(int node){
        if(vis[node] == 1) return;
        
        vis[node] = 1;
        set<int> v;
        for(auto c: adj[node]){
            dfs(c);
            v.insert(c);
            for(auto x: m[c])
                v.insert(x);
        }
        
        m[node] = v;
        
    }
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& a) {
        adj.resize(n + 1);
        vis.resize(n + 1, 0);
        
        vector<int> b(n + 1, 0);
        
        for(int i = 0; i < a.size(); i++){
            adj[a[i][1]].push_back(a[i][0]);
            b[a[i][0]] ++;
        }
        for(int i = 0; i < n; i++){
            if(b[i] == 0)
                dfs(i);
        }
        
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            vector<int> v;
            for(auto c: m[i])
                v.push_back(c);
            
            ans.push_back(v);
        }
        
        return ans;
        
    }
};