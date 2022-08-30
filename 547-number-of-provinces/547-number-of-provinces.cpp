class Solution {
public:
    vector<int> vis, rank, par;
    
    int findpar(int x){
        if(par[x] == x) return x;
        return findpar(par[x]);
    }
    
    void unionp(int u, int v){
        int x = findpar(u);
        int y = findpar(v);
        
        if(rank[x] > rank[y]){
            par[y] = x;
        }
        else if(rank[y] > rank[x])
            par[x] = y;
        else{
            par[x] = y;
            rank[y]++;
        }
    }
    
    int findCircleNum(vector<vector<int>>& a) {
        int n = a.size();
        vis.resize(n + 1, 0);
        rank.resize(n + 1);
        par.resize(n + 1);
        
        for(int i = 0; i <= n; i++){
            rank[i] = 0, par[i] = i;
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(a[i][j])
                    unionp(i, j);
            }    
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            // int x = findpar(i);
            if(par[i] == i) ans++;
        }
        
        return ans;
    }
};