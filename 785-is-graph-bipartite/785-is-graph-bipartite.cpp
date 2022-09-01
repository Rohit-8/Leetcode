class Solution {
public:
    
    vector<int> c;
    bool dfs(vector<vector<int>> &a, int node, vector<int> &c, int col){
        if(c[node] != -1 and c[node] != col) return false;
        c[node] = col;
        for(auto x: a[node]){
            if(c[x] == -1){
                if(dfs(a, x, c, !col)) return true;
            }
            else if(c[x] == c[node]) return true;
        }
        return false;
    }
    
    bool isBipartite(vector<vector<int>>& a) {
        int n = a.size();
        c = vector<int> (n + 1, -1);
        
        for(int i = 0; i < n; i++){
            if(c[i] == -1){
                if(dfs(a, i, c, 0)) return false;
            }
        }
        
        return true;
    }
};