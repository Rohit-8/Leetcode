class Solution {
public:
    int res(string &s, string &t, int i, int j, vector<vector<int>> &dp){
        if(s.size() <= i or t.size() <= j){
            return max(s.size() - i, t.size() - j);
        }
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s[i] == t[j])
            return dp[i][j] = res(s, t, i + 1, j + 1, dp);
        return dp[i][j] = 1 + min({res(s, t, i, j + 1, dp), res(s, t, i + 1, j + 1, dp), res(s, t, i + 1, j, dp)});
    }
    int minDistance(string s, string t) {
        vector<vector<int>> dp(s.size() + 1, vector<int> (t.size() + 1, -1));
        return res(s, t, 0, 0, dp);
    }
};