class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int res(vector<vector<int>> &a, int i, int j){
        if(i >= n or j >= n or j > i)
            return 0;
        
        if(i == n-1) return a[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        
        return dp[i][j] = min(res(a, i + 1, j), res(a, i + 1, j + 1)) + a[i][j];
    }
    
    int minimumTotal(vector<vector<int>>& a) {
        n = a.size();
        dp.resize(n, vector<int> (n, -1));
        return res(a, 0, 0);
    }
};