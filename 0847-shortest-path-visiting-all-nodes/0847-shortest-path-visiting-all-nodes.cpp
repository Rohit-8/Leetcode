class Solution {
public:
    int shortestPathLength(vector<vector<int>>& adj) {
        int n = adj.size();
        int num = (1 << n) - 1;
        queue<pair<int,int>> q;
        map<pair<int,int>, int> ump;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            int p = 1<<i;
            q.push({i,p});
            ump[{i,p}]++;
        }
        
        int path = 0;
        while(!q.empty()){
            int sz = q.size();
            path++;
            while(sz--){
                
                auto [a,b] = q.front(); q.pop();
                for(auto p : adj[a]){
                    
                    int check_bit = b | (1<<p);
                    if(check_bit == num)return path;
                    if(!ump[{p,check_bit}]){
                        q.push({p, check_bit});
                        ump[{p,check_bit}]++;
                    }
                }
            }
        }
        
        return 0;
    }
};