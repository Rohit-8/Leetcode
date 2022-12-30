class Solution {
public:
    int uniquePaths(int n, int m) {
        vector<int> dp(m, 1);
        for(int i = 1; i < n; i++){
            vector<int> v(m, 0);
            for(int j = 0; j < m; j++){
                if(j == 0)
                    v[j] = 1;
                else{
                    v[j] = v[j - 1] + dp[j];
                }
            }
            dp = v;
        }
        return dp[m - 1];
    }
};