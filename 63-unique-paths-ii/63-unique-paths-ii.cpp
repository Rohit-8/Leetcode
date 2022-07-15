class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        vector<int> dp(m, 0);
        if(a[0][0] == 1) return 0;
        dp[0] = 1;
        
        for(int i = 1; i < m; i++)
            if(a[0][i] == 0)
                dp[i] = dp[i-1];
        
        int prev = 0;
        for(int i = 1; i < n; i++){
            vector<int> p(m, 0); prev = 0;
            for(int j = 0; j < m; j++){
                if(a[i][j] == 0)
                    p[j] = dp[j] + prev;
                prev = p[j];
            }
            dp = p;
        }
        
        return dp[m-1];
    }
};