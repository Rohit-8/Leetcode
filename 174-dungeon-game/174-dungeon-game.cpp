class Solution {
public:
    // int ans = INT_MAX;
    int n, m;
    vector<vector<int>> dp;
    
    int res(vector<vector<int>> &a, int i, int j){
        if(i >= n or j >= m) return -1e9;
        
        if(i == n-1 and j == m-1) return dp[i][j] = a[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int d, r;
        d = min(a[i][j], res(a, i+1, j) + a[i][j]);
        r = min(a[i][j], res(a, i, j+1) + a[i][j]);
        
        return dp[i][j] = max(d, r);
    }
    
    int calculateMinimumHP(vector<vector<int>>& a) {
        n = a.size(), m = a[0].size();
        dp.resize(n+1, vector<int> (m+1, -1));
        
        int x = res(a, 0, 0);
        if(x >= 0) return 1;
        return x*(-1) + 1;
    }
};