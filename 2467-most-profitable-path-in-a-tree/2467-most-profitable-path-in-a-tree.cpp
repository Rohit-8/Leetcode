class Solution {
public:
    unordered_map<int, int> path;
    long long dfs(vector<vector<int>> &adj, vector<int> &a, vector<int> &vis, int node, int x){
        if(vis[node]) return 0;
        long long sum = 0;
        if(x == node){
            sum = a[node] / 2;
            a[node] = 0;
        }
        else {
            sum = a[node];
            a[node] = 0;
        }
        
        vis[node] = 1;
        long long d = INT_MIN;
        bool f = false;
        for(auto c: adj[node]){
            if(vis[c] == 0){
                d =  max(d,dfs(adj, a, vis, c, path[x]));
                f = true;
            }
        }
        if(f)
            sum += d;
        return sum;
    }
    
    int mostProfitablePath(vector<vector<int>>& a, int bob, vector<int>& am) {
        
        vector<vector<int>> adj(a.size() + 1);
        for(int i = 0; i < a.size(); i++){
            adj[a[i][0]].push_back(a[i][1]);
            adj[a[i][1]].push_back(a[i][0]);
        }
        
        queue<int> q;
        q.push(0);
        path[0] = 0;
        
        while(!q.empty()){
            int n = q.size();
            
            bool f = false;
            for(int i = 0; i < n; i++){
                int c = q.front();
                q.pop();
                for(auto x: adj[c]){
                    if(path.count(x) == false){
                        path[x] = c;
                        q.push(x);
                    }
                    if(x == bob){
                        f = true;
                        break;
                    }
                }
                if(f) break;
            }
            
            if(f) break;
        }
        int c = 0;
        int x = bob;
        while(1){
            c++;
            if(x == 0) break;
            x = path[x];
            
        }
        x = c / 2;
        c = bob;
        while(x--){
            am[c] = 0;
            c = path[c];
        }
        vector<int> vis(a.size() + 1, 0);
        
        return dfs(adj, am, vis, 0, bob);
    }
};