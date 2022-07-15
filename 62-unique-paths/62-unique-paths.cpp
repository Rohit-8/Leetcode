class Solution {
public:
    int uniquePaths(int n, int m) {
        vector<int> dp(m, 0);
        
        for(int i = 0; i < m; i++)
            dp[i] = 1;
        
        int prev = 0;
        for(int i = 1; i < n; i++){
            vector<int> p(m); prev = 0;
            for(int j = 0; j < m; j++){
                p[j] = dp[j] + prev;
                prev = p[j];
            }
            dp = p;
        }
        
        return dp[m-1];
    }
};