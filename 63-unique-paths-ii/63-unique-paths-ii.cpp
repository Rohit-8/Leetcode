class Solution {
public:
    int n, m;
    vector<vector<int>> dp;
    
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        n = a.size(), m = a[0].size();
        if(a[n-1][m-1] == 1 or a[0][0] == 1) return 0;
        dp.resize(n + 1, vector<int> (m + 1, -1));
        
        int prev = 1;
        for(int i = 0; i < n; i++){
            if(a[i][0] == 1) prev = 0;
            dp[i][0] = prev;
        }
        prev = 1;
        for(int i = 0; i < m; i++){
            if(a[0][i] == 1) prev = 0;
            dp[0][i] = prev;
        }
        
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(a[i][j] == 1) dp[i][j] = 0;
                else dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[n-1][m-1];
    }
};