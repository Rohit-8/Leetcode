class Solution {
public:
    
    int n, m;
    void dfs(vector<vector<char>>& a, int i, int j){
        if(i >= n or j >= m or i < 0 or j < 0 or a[i][j] != 'O') return;
        
        a[i][j] = '.';
        
        dfs(a, i+1, j);
        dfs(a, i, j-1);
        dfs(a, i-1, j);
        dfs(a, i, j+1);
    }
    
    void solve(vector<vector<char>>& a) {
        n = a.size(), m = a[0].size();
        
        for(int i = 0; i < n; i += max(n-1, 1))
            for(int j = 0; j < m; j++)
                if(a[i][j] == 'O') dfs(a, i, j);
        
        for(int i = 1; i < n - 1; i++)
            for(int j = 0; j< m; j += max(1,m-1))
                if(a[i][j] == 'O') dfs(a, i, j);
        
        for(int i =0; i <n; i++)
            for(int j = 0; j < m; j++){
                if(a[i][j] == '.') a[i][j] = 'O';
                else if(a[i][j] == 'O') a[i][j] = 'X';
            }
        
    }
};