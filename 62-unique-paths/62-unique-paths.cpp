class Solution {
public:
    int uniquePaths(int n, int m) {
        if(n == 1 or m == 1) return 1; 
        vector<int> dp(m), a(m, 1);
        int prev = 1;
        
        for(int i = 1; i < n; i++){
            prev = 1;
            for(int j = 1; j < m; j++){
                dp[j] = a[j] + prev;
                prev = dp[j];
            }
            a = dp;
        }
        return dp[m-1];
    }
};