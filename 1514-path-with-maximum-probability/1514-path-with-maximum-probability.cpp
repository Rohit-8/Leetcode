class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& a, vector<double>& sp, int l, int r) {
         
        vector<vector<pair<int, double>>> adj(n);
        for(int i = 0; i < a.size(); i++){
            adj[a[i][0]].push_back({a[i][1],sp[i]});
            adj[a[i][1]].push_back({a[i][0],sp[i]});
        }
        
        priority_queue<pair<double, int>> pq;
        vector<double> ans(n);
        ans[l] = 1;
        pq.push({1, l});
        
        while(!pq.empty()){
            
            int node = pq.top().second;
            double prevp = pq.top().first;
            pq.pop();
            for(auto x : adj[node]){
                if(prevp*x.second > ans[x.first]){
                    ans[x.first] = prevp * x.second;
                    pq.push({ans[x.first], x.first});
                }
            }
            
        }
        
        return ans[r];
    }
};