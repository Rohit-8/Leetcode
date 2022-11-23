class Solution {
public:
    int res(vector<vector<int>> &a, int i, int j, vector<vector<int>> &dp){
        if(i < 0 or j < 0 or i >= a.size() or j >= a[0].size())
            return 1e9;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int sum = a[i][j];
        if(i == a.size() - 1 and j == a[0].size() -1)
            return dp[i][j] = sum;
        
        sum += min(res(a, i + 1, j, dp), res(a, i, j + 1, dp));
        return dp[i][j] = sum;
    }
    int minPathSum(vector<vector<int>>& a) {
        vector<vector<int>> dp(a.size() + 1, vector<int> (a[0].size() + 1, -1));
        return res(a, 0, 0, dp);   
    }
};