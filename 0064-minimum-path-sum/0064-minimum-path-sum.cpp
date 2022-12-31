class Solution {
public:
//     int res(vector<vector<int>> &a, int i, int j, vector<vector<int>> &dp){
//         if(i < 0 or j < 0 or i >= a.size() or j >= a[0].size())
//             return 1e9;
        
//         if(dp[i][j] != -1)
//             return dp[i][j];
        
//         int sum = a[i][j];
//         if(i == a.size() - 1 and j == a[0].size() -1)
//             return dp[i][j] = sum;
        
//         sum += min(res(a, i + 1, j, dp), res(a, i, j + 1, dp));
//         return dp[i][j] = sum;
//     }
    
    int minPathSum(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        // vector<vector<int>> dp(a.size() + 1, vector<int> (a[0].size() + 1, -1));
        // return res(a, 0, 0, dp);   
        
        
        ///// method 2 /////
        
//         vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
//         dp[0][0] = a[0][0];
//         for(int i = 1; i < n; i++){
//             dp[i][0] = dp[i-1][0] + a[i][0];
//         }
//         for(int i = 1; i < m; i++){
//             dp[0][i] = dp[0][i-1] + a[0][i];
//         }
        
//         for(int i = 1; i < n; i++){
//             for(int j = 1; j < m; j++){
//                 dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + a[i][j];
//             }
//         }
        
//         return dp[n-1][m-1];
        
        ////// method 3 space ////////////
        vector<int> dp(m, 0);
        dp[0] = a[0][0];
        for(int i = 1; i < m; i++){
            dp[i] = dp[i - 1] + a[0][i];
        }
        
        for(int i = 1; i < n; i++){
            vector<int> v(m, 0);
            for(int j = 0; j < m; j++){
                if(j == 0)
                    v[j] = dp[j] + a[i][j];
                else {
                    v[j] = a[i][j] + min(dp[j], v[j - 1]);
                }
            }
            dp = v;
        }
        
        return dp[m - 1];
    }
};