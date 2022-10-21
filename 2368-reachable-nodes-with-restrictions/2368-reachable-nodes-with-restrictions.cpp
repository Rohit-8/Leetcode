class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& a, vector<int>& r) {
        map<int, int> m;
        for(int i = 0; i < r.size(); i++){
            m[r[i]]++;
        }
        
        vector<vector<int>> adj(n);
        for(int i = 0; i < a.size(); i++){
            adj[a[i][0]].push_back(a[i][1]);
            adj[a[i][1]].push_back(a[i][0]);
        }
        
        queue<int> q;
        q.push(0);
        m[0]++;
        int ans = 0;
        
        while(!q.empty()){
            int x = q.size();
            ans += x;
            
            for(int i = 0; i < x; i++){
                int d = q.front();
                q.pop();
                for(auto c : adj[d]){
                    if(!m[c]) q.push(c), m[c]++;
                }
            }
        }
        
        return ans;
    }
};