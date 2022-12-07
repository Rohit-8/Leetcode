class Solution {
public:
//     int lps(string &s, string &t, int i, int j, vector<vector<int>> &dp){
//         if(i >= s.size() or j >= t.size())
//             return 0;
        
//         if(dp[i][j] != -1)
//             return dp[i][j];
        
//         if(s[i] == t[j])
//             return dp[i][j] = 1 + lps(s, t, i + 1, j + 1, dp);
//         return dp[i][j] = max(lps(s, t, i + 1, j, dp), lps(s, t, i, j + 1, dp));
//     }
    
    int minInsertions(string &s) {
//         string t = s;
//         vector<vector<int>> dp(s.size() + 1, vector<int> (s.size() + 1, -1));
//         reverse(t.begin(), t.end());
//         int lp = lps(s, t, 0, 0, dp);
        
//         return s.size() - lp;
        
        int n = s.length(),i,j,ans = 0;
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        string s2 = s;
        reverse(s2.begin(),s2.end());
        for(i = 1; i<=n; i++){
            for(j = 1; j<=n; j++){
                if(s[i-1]==s2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }else{
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
                ans = max(ans,dp[i][j]);
            }
        }
        return n - ans;
    }
};