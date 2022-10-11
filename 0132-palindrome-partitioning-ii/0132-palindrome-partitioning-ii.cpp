class Solution {
public:
    bool pal(string &s, int i, int j){
        for(int k = 0; k <= (j - i) / 2; k++){
            if(s[i + k] != s[j - k]) return false;
        }
        return true;
    }
    vector<vector<int>> dp;
    int res(string s, int i, int j){
        if(i >= j) return dp[i][j] = 0;
        if(pal(s, i, j)) return dp[i][j] = 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int mn = INT_MAX;
        for(int k = i; k < j; k++){
            if(pal(s, i, k)){
                int t = res(s, k + 1, j) + 1;
                mn = min(mn, t);
            }
        }
    
        return dp[i][j] = mn;
    }
    
    int minCut(string &s) {
        dp.resize(s.size() + 1, vector<int> (s.size() + 1, -1));
        return res(s, 0, s.size() - 1);
    }
};