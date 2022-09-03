class Solution {
public:
    vector<vector<int>> dp;
    int res(int n, int m){
        if(n == 0 or m == 0)
            return 1;
        if(dp[n][m] != -1) return dp[n][m];
        return dp[n][m] = res(n-1, m) + res(n, m-1);
    }
    int uniquePaths(int n, int m) {
        dp.resize(n, vector<int> (m, -1));
        return res(n-1, m-1);
    }
};