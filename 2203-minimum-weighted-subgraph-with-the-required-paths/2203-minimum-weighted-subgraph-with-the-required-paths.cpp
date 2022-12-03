class Solution {
public:
    vector<long long> dijk(vector<vector<pair<long long,long long>>> &adj, int src){
        
        vector<long long> dis(adj.size(), 1e18);
        
        priority_queue<pair<long long, long long>, vector<pair<long long,long long>> ,greater<pair<long long,long long>>> pq;
        dis[src] = 0;
        pq.push({0, src});
        
        while(!pq.empty()){
            pair<long long, long long> tmp = pq.top();
            pq.pop();
            int u = tmp.second;
            
            if (tmp.first != dis[u]) continue;
            
            for(auto x : adj[u]){
                long long v = x.first;
                long long dt = x.second;
                
                if(dis[u] + dt < dis[v]){
                    dis[v] = dis[u] + dt;
                    pq.push({dis[v], v});
                }
            }
        }
        
        return dis;
    }
    
    long long minimumWeight(int n, vector<vector<int>>& a, int src1, int src2, int dest) {
        vector<vector<pair<long long, long long>>> adj(n), rev(n);
        for(int i = 0; i < a.size(); i++){
            rev[a[i][1]].push_back({a[i][0], a[i][2]});
            adj[a[i][0]].push_back({a[i][1], a[i][2]});
        }
        
        vector<long long> d1 = dijk(adj, src1);
        vector<long long> d2 = dijk(adj, src2);
        vector<long long> d = dijk(rev, dest);
        
        long long ans = 1e18;
        
        for(int i = 0; i < n; i++){
            ans = min(ans, d1[i] + d2[i] + d[i]);
        }
        if(ans >= 1e18) return -1;
        
        return ans;
    }
};