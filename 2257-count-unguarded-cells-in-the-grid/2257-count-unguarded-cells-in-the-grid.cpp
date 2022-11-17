class Solution {
public:
    void res(vector<vector<int>> &v, int k, int l){
        // int j = l;
        for(int i = k - 1; i >= 0 and v[i][l] != 2 and v[i][l] != 3; i--){
            // if(v[i][l] == 0)
            v[i][l] = 3;
        }
        for(int i = k + 1; i < v.size() and v[i][l] != 2 and v[i][l] != 3; i++){
            // if(v[i][l] == 0)
            v[i][l] = 3;
        }
        
        for(int j = l - 1; j >= 0 and v[k][j] != 2 and v[k][j] != 4; j--){
            // if(v[k][j] == 0)
            v[k][j] = 4;
        }
        for(int j = l + 1; j < v[0].size() and v[k][j] != 2 and v[k][j] != 4; j++){
            // if(v[k][j] == 0)
            v[k][j] = 4;
        }
        // v[k][l] = 2;
    }
    
    int countUnguarded(int n, int m, vector<vector<int>>& g, vector<vector<int>>& w) {
        vector<vector<int>> v(n, vector<int> (m, 0));
        for(int i = 0; i < w.size(); i++){
            v[w[i][0]][w[i][1]] = 2;
        }
        
        for(int i = 0; i < g.size(); i++){
            v[g[i][0]][g[i][1]] = 2;
        }
        
        for(int i = 0; i < g.size(); i++){
            res(v, g[i][0], g[i][1]);
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                // cout<<v[i][j]<<" ";
                if(v[i][j] == 0) ans++;
            }
            // cout<<endl;
        }
        
        return ans;
    }
};