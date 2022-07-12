class Solution {
public:
    bool solve(string &s, string &p, int n, int m, vector<vector<int>>&dp){
        if(n == 0 && m == 0) return true;
        if(m==0 && n!=0) return false;
        
        if(n==0 && m!=0 && p[m-1] == '*'){
            for(int i = m-1; i>=0; i-=2){
                if(p[i] != '*') return false;
            }
            return true;
        }
        
        if(n==0 && m!=0) return false;
        if(dp[n][m] != -1) return dp[n][m];
        
        if(s[n-1] == p[m-1] || p[m-1] == '.'){
            return dp[n][m] = solve(s,p,n-1,m-1,dp);
        }
        
        else if(p[m-1] == '*'){
            if(p[m-2] == s[n-1] || p[m-2] == '.'){
                return dp[n][m] = solve(s,p,n-1,m,dp) || solve(s,p,n,m-2,dp);
            }
            else{
                return dp[n][m] = solve(s,p,n,m-2,dp);
            }
        }
        return dp[n][m] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(s,p,n,m,dp);
    }
};