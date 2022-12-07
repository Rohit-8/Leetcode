class Solution {
public:
    int lps(string &s, string &t, int i, int j, vector<vector<int>> &dp){
        if(i >= s.size() or j >= t.size())
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s[i] == t[j])
            return dp[i][j] = 1 + lps(s, t, i + 1, j + 1, dp);
        return dp[i][j] = max(lps(s, t, i + 1, j, dp), lps(s, t, i, j + 1, dp));
    }
    
    int minInsertions(string s) {
        string t = s;
        vector<vector<int>> dp(s.size() + 1, vector<int> (s.size() + 1, -1));
        reverse(t.begin(), t.end());
        int lp = lps(s, t, 0, 0, dp);
        
        return s.size() - lp;
    }
};