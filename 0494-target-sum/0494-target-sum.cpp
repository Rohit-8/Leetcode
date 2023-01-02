class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int t) {
        int n = arr.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
        }
        if((sum + t) % 2) return 0;
        sum = (sum + t) / 2;
        if(sum < 0)
            sum += 1000;
        vector<vector<int>> dp(n + 1, vector<int> (sum + 1, 0));
        // dp[0][0] = 1;
        int mod = 1000000007;
        for(int i = 0; i <= n; i++){
            dp[i][0] = 1;
        }
        
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= sum; j++){
                // not take
                dp[i][j] = dp[i - 1][j];
                // if can take
                if(j >= arr[i - 1]){
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - arr[i - 1]]) % mod;
                }
            }
        }
        
        return dp[n][sum] % mod;
    }
};