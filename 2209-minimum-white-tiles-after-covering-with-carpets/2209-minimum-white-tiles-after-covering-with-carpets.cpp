class Solution {
public:
    // int ans = INT_MAX;
    int res(string &s, int n, int nc, int cl, vector<vector<int>> &dp){
        if(n >= s.size() or nc <= 0){
            // int c = 0;
            // for(int i = 0; i < s.size(); i++){
            //     if(s[i] == '1') c++;
            // }
            // ans = min(ans, c);
            return 0;
        }
        if(dp[n][nc] != -1)
            return dp[n][nc];
        
        int l = res(s, n + 1, nc, cl, dp);
        
        if(s[n] == '1'){
            int c = 0;
            for(int i = n; i < s.size() and i < n + cl; i++)
                if(s[i] == '1'){
                    // s[i] = '0';
                    c ++;
                }
            
            l = max(l, c + res(s, n + cl, nc - 1, cl, dp));
            // for(int i = n; i < s.size() and i < n + cl; i++)
            //     s[i] = '1';
        }
        return dp[n][nc] = l;
    }
    
    int minimumWhiteTiles(string s, int nc, int cl) {
        vector<vector<int>> dp(s.size() + 1, vector<int> (nc + 1, -1));
        int c = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1') c++;
        }
        return c - res(s, 0, nc, cl, dp);
        
        // return ans;
    }
};