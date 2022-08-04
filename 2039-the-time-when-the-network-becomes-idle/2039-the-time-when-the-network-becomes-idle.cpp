class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& a, vector<int>& p) {
        vector<int> adj[p.size() + 1];
        int n = p.size();
        for(int i = 0; i < a.size(); i++){
            adj[a[i][0]].push_back(a[i][1]);
            adj[a[i][1]].push_back(a[i][0]);
        }
        
        queue<int> q;
        q.push(0);
        vector<int> vis(n + 1, 0);
        // vis[0] = 1;
        
        long long ans = 0;
        int c = 0;
        while(!q.empty()){
            int k = q.size();
            
            for(int i = 0; i < k; i++){
                int x = q.front();
                q.pop();
                if(vis[x]) continue;
                
                vis[x] = 1;
                for(auto d: adj[x]){
                    if(vis[d] == 0)
                        q.push(d);
                }
                if(x == 0) continue;
                
                long long y = ((c * 2)*1ll / p[x]);
                if((c * 2) % p[x]) y++;
                
                y--;
                y *= (p[x]*1ll);
                y += (c * 2*1ll);
                
                ans = max(ans, y);
            }
            
            c++;
        }
        
        return ans + 1;
    }
};