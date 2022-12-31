class Solution {
public:
    int n;
    // vector<vector<int>> dp;
//     int res(vector<vector<int>> &a, int i, int j){
//         if(i >= n or j >= n or j > i)
//             return 0;
        
//         if(i == n-1) return a[i][j];
//         if(dp[i][j] != -1) return dp[i][j];
        
//         return dp[i][j] = min(res(a, i + 1, j), res(a, i + 1, j + 1)) + a[i][j];
//     }
    
    int minimumTotal(vector<vector<int>>& a) {
        n = a.size();
        // dp.resize(n, vector<int> (n, -1));
        // return res(a, 0, 0);
        
        //// method 2 ////////
        vector<int> dp(n, 0);
        dp[0] = a[0][0];
        
        for(int i = 1; i < n; i++){
            vector<int> v(n, 0);
            v[0] = a[i][0] + dp[0];
            for(int j = 1; j < i; j++){
                v[j] = a[i][j] + min(dp[j - 1], dp[j]);
            }
            v[i] = a[i][i] + dp[i - 1];
            dp = v;
        }
        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            ans = min(ans, dp[i]);
        }
        return ans;
    }
};