class Solution {
public:
    int n;
//     vector<vector<int>> dp;
//     int res(vector<vector<int>> &a, int i, int j){
//         if(i >= n or j >= n or i < 0 or j < 0)
//             return 1e9;
        
//         if(i == n-1) return a[i][j];
//         if(dp[i][j] != -1) return dp[i][j];
        
//         return dp[i][j] = min({res(a, i + 1, j), res(a, i + 1, j + 1), res(a, i + 1, j - 1)}) + a[i][j];
//     }
    
    int minFallingPathSum(vector<vector<int>>& a) {
        n = a.size();
        // dp.resize(n + 1, vector<int> (n + 1, -1));
        // int ans = INT_MAX;
        // for(int i = 0; i < n; i++){
        //     ans = min(res(a, 0, i), ans);
        // }
        // return ans;
        
        //////// method 2 //////////
        vector<int> dp(n, 0);
        dp = a[0];
        
        for(int i = 1; i < n; i++){
            vector<int> v(n, 0);
            // v[0] = a[i][0] + dp[0];
            for(int j = 0; j < n; j++){
                v[j] = a[i][j];
                int x = dp[j];
                if(j > 0){
                    x = min(x, dp[j - 1]);
                }
                if(j < n - 1)
                    x = min(x, dp[j + 1]);
                v[j] += x;
            }
            dp = v;
        }
        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            ans = min(ans, dp[i]);
        }
        return ans;
    }
};