class Solution {
public:
    vector<int> p = {-1, 0, 1};
    int res(vector<vector<int>> &a, int i, int j, int k, vector<vector<vector<int>>> &dp){
        if(i >= a.size() or j < 0 or k < 0 or j >= a[0].size() or k >= a[0].size())
            return 0;
        
        if(dp[i][j][k] != -1)
            return dp[i][j][k];
        
        int sum = 0;
        if(j == k)
            sum += a[i][j];
        else sum += a[i][j] + a[i][k];
        
        int r = 0;
        for(int x = 0; x < 3; x++){
            for(int t = 0; t < 3; t++){
                r = max(r, res(a, i + 1, j + p[x], k + p[t], dp));
            }
        }
        
        return dp[i][j][k] = sum + r;
    }
    int cherryPickup(vector<vector<int>>& a) {
        vector<vector<vector<int>>> dp(a.size() + 1, vector<vector<int>> (a[0].size() + 1, vector<int> (a[0].size() + 1, -1)));
        return res(a, 0, 0, a[0].size() - 1, dp);
    }
};