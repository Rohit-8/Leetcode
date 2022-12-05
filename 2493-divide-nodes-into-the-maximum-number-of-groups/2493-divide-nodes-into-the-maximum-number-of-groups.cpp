class Solution {
public:
    bool dfs(vector<vector<int>> &a, int node, vector<int> &c, int col){
        if(c[node] != -1 and c[node] != col) return false;
        c[node] = col;
        for(auto x: a[node]){
            if(c[x] == -1){
                if(dfs(a, x, c, !col)) return true;
            }
            else if(c[x] == c[node]) return true;
        }
        return false;
    }
    
    int res(vector<vector<int>> &adj, int node, vector<int> &vis){
        queue<int> q;
        q.push(node);
        int t = 0;
        while(!q.empty()){
            int n = q.size();
            t++;
            for(int i = 0; i < n; i++){
                int x = q.front();
                q.pop();
                vis[x] = 1;
                for(auto c : adj[x]){
                    if(vis[c] == 0){
                        q.push(c);
                    }
                }
            }
        }
        
        return t;
    }
    
    int magnificentSets(int n, vector<vector<int>>& a) {
        vector<int> vis(n + 1, 0);
        vector<vector<int>> adj(n + 1);
        
        for(int i = 0; i < a.size(); i++){
            adj[a[i][0]].push_back(a[i][1]);
            adj[a[i][1]].push_back(a[i][0]);
        }
        vector<int> c(n + 1, -1);
        for(int i = 1; i <= n; i++){
            if(c[i] == -1){
                if(dfs(adj, i, c, 0)) return -1;
            }
        }
        
        vector<int> dis(n+5, n+5);
        queue<int>q;
        vector<int> s(n+5,0);
        for(int i=1;i<=n;++i){
            q.push(i);
            fill(dis.begin(),dis.end(),n+5);
            dis[i]=0;
            int mx=0,mi=i;
            while(!q.empty()){
                int x=q.front();q.pop();
                for(int v:adj[x])
                    if(dis[v]==n+5){
                    dis[v]=dis[x]+1;
                    mx=max(mx,dis[v]);
                    mi=min(mi,v);
                    q.push(v);
                }
            }
            s[mi]=max(s[mi],mx+1);
        }
        int ans=0;
        for(int i=1;i<=n;++i){
            ans+=s[i];
        }
        return ans;
    }
};