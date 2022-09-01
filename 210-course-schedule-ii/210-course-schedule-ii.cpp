class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& a) {
        vector<int> adj[n];
        
        for(int i = 0; i < a.size(); i++){
            int first = a[i][0];
            int second = a[i][1];
            adj[second].push_back(first);
        }
        
        vector<int> indegree(n, 0);
        for(int i = 0; i < n; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        
        vector<int> topo;
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] <= 0){
                    q.push(it);
                }
            }
        }
        if(topo.size() != n) return {};
        
        return topo;
    }
};