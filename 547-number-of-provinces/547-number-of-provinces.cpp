class Solution {
public:
    
    deque<int> vis;
    deque<vector<int>> adj;
    
    void dfs(int node){
        vis[node] = 1;
        for(auto x: adj[node])
            if(vis[x] == 0)
                dfs(x);
    }
    
    int findCircleNum(vector<vector<int>>& a) {
        int n = a.size();
        adj.resize(n + 1, vector<int> (n + 1));
        vis.resize(n + 1, 0);
        
        for(int i = 0; i < n; i++){
            // int x = i;
            for(int j = 0; j < n; j++){
                if(a[i][j]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++)
            if(vis[i] == 0){
                ans++;
                dfs(i);
            }
        
        return ans;
    }
};