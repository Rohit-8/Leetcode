class Solution {
public:
    int n, m;
    vector<vector<int>> dp;
    int res(vector<vector<int>> &a, int i, int j){
        if(i >= n or j >= m or i < 0 or j < 0 or a[i][j] == 1)
            return 0;
        if(i == 0 and j == 0) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = res(a, i-1, j) + res(a, i, j-1);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        n = a.size(), m = a[0].size();
        if(a[n-1][m-1] == 1 or a[0][0] == 1) return 0;
        dp.resize(n + 1, vector<int> (m + 1, -1));
        
        return res(a, n - 1, m - 1);
    }
};