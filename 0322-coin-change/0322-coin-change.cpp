class Solution {
public:
//     int res(vector<int> &a, int n, int sum, vector<vector<int>> &dp){
//         if(sum == 0)
//             return 0;
//         if(n < 0)
//             return 1e9;
//         if(dp[n][sum] != -1)
//             return dp[n][sum];
//         int l = res(a, n - 1, sum, dp);
//         if(sum >= a[n]){
//             l = min(1 + res(a, n, sum - a[n], dp), l);
//         }
        
//         return dp[n][sum] = l;
//     }
    
    int coinChange(vector<int>& coins, int sum) {
        // vector<vector<int>> dp(a.size() + 1, vector<int> (sum + 1, -1));
        // int x = res(a, a.size() - 1, sum, dp);
        // if(x < 1e9)
        //     return x;
        // return -1;
        
        /////////// method 2 //////////
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int> (sum + 1, 1e9));
        for(int i = 0; i <= n; i++){
            dp[i][0] = 0;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= sum; j++){
                dp[i][j] = dp[i - 1][j];
                if(j >= coins[i - 1])
                    dp[i][j] = min(dp[i][j], 1 + dp[i][j - coins[i - 1]]);
            }
        }
        
        if(dp[n][sum] >= 1e9)
            return -1;
        return dp[n][sum];
    }
};