class Solution {
public:
    
//     bool res(vector<int> &a, int sum, int i){
//         if(i < 0) return false;
//         if(sum == 0) return true;
        
//         if(dp[i][sum] != -1) return dp[i][sum];
        
//         bool f = res(a, sum, i - 1);
//         if(sum - a[i] >= 0)
//             f |= res(a, sum - a[i], i - 1);
        
//         return dp[i][sum] = f;
//     }
    
    bool canPartition(vector<int>& a) {
        int sum = 0;
        int n;
        
        n = a.size();
        for(int i = 0; i < n; i++){
            sum += a[i];
        }
        if(sum % 2) return false;
        vector<vector<bool>> dp;
        dp.resize(n + 1, vector<bool> (sum / 2 + 1, false));
        int m = sum / 2;
        for(int i = 0; i < n; i++){
            dp[i][0] = true;
        }
        
        for(int i = 1; i < n; i++){
            for(int j = 1; j <= m; j++){
                dp[i][j] = dp[i - 1][j];
                if(a[i - 1] <= j)
                    dp[i][j] = dp[i][j] | dp[i - 1][j - a[i - 1]];
            }
        }
        
        return dp[n - 1][m];
    }
};