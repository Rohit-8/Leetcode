class Solution {
public:
    vector<vector<int>> adj;
    vector<int> vis;
    unordered_map<int,set<int>> m;
    
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
    
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& a, vector<vector<int>>& q) {
        adj.resize(n + 1);
        vis.resize(n + 1, 0);
        
        vector<int> b(n + 1, 0);
        
        for(int i = 0; i < a.size(); i++){
            adj[a[i][0]].push_back(a[i][1]);
            b[a[i][1]] ++;
        }
        for(int i = 0; i < n; i++){
            if(b[i] == 0)
                dfs(i);
        }
        
        vector<bool> ans;
        for(int i = 0; i < q.size(); i++){
            vector<int> x = q[i];
            bool f = true;
            for(auto c: m[x[0]])
                if(c == x[1]){
                    f =false;
                    ans.push_back(true); break;
                }
            
            if(f) ans.push_back(false);
        }
        
        return ans;
    }
};