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
        vector<vector<int>> dp(a.size() + 1, vector<int> (a[0].size() + 1, -1));
        
        return helper(a, 0, 0, dp);
    }
};