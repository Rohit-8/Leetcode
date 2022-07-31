class Solution {
public:
    int minReorder(int n, vector<vector<int>>& a) {
        vector<bool> vis(a.size()+1, false);
        set<pair<int,int>> m;
        vector<int> adj[a.size()+1];
        
        for(int i = 0; i < a.size(); i++){
            
            adj[a[i][0]].push_back(a[i][1]);
            adj[a[i][1]].push_back(a[i][0]);
            m.insert({a[i][0], a[i][1]});
        }
        
        queue<int> q;
        q.push(0);
        int ans = 0;
        // vis[0] = true;
        
        while(!q.empty()){
            int k = q.front();
            // vis[k] = true;
            q.pop();
            
            if(vis[k] == false){
                vis[k] = true;
                for(auto c: adj[k]){
                    // q.push(c);
                    if(vis[c] == false){
                        q.push(c);
                        if(vis[c] == false and m.count({k, c})) 
                            ans++;
                    }
                }
            }
        }
        
        return ans;
        
    }
};