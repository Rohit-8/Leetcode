class Solution {
public:
    
    int res(vector<vector<int>> &t, int i, int j, int n, vector<vector<int>> &dp){
        if(i >= n) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        int sum = min(res(t, i+1, j, n, dp), res(t, i+1, j+1, n, dp)) + t[i][j];
    
        return dp[i][j] = sum;
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        
        return res(triangle, 0, 0, n, dp);
    }
};