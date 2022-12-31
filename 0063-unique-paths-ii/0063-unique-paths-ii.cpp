class Solution {
public:
    int helper(vector<vector<int>> &a, int i, int j, vector<vector<int>> &dp){
        if(i == a.size() - 1 and j == a[0].size() - 1 and a[i][j] != 1)
            return 1;
        if(i >= a.size() or j >= a[0].size() or a[i][j] == 1)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = helper(a, i + 1, j, dp) + helper(a, i, j + 1, dp);
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        // vector<vector<int>> dp(a.size() + 1, vector<int> (a[0].size() + 1, -1));
        
        // return helper(a, 0, 0, dp);
        ///////////// method 2 ///////////////
        int n = a.size(), m = a[0].size();
        if(a[n - 1][m - 1] or a[0][0])
            return 0;
        vector<vector<int>> dp(a.size() + 1, vector<int> (a[0].size() + 1, 0));
        dp[0][0] = 1;
        for(int i = 1; i < m; i++){
            if(a[0][i] == 1)
                dp[0][i] = 0;
            else dp[0][i] = dp[0][i - 1];
        }
        for(int i = 1; i < n; i++){
            if(a[i][0] == 1)
                dp[i][0] = 0;
            else dp[i][0] = dp[i - 1][0];
        }
        
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(a[i][j] == 1){
                    dp[i][j] = 0;
                }
                else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        
        return dp[n - 1][m - 1];
    }
};