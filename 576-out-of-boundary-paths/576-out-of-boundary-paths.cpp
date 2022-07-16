#define mod 1000000007
#define ll long long
class Solution {
public:
    
    vector<vector<vector<ll>>> dp;
    
    int dfs(int n, int m, int i , int j, int moves){
        if(i < 0 or j < 0 or i >= n or j >= m){
            return 1;
        }
        
        if(moves <= 0) return 0;
        if(dp[i][j][moves] != -1) return dp[i][j][moves];
        
        ll lm = dfs(n, m, i, j-1, moves - 1);
        ll rm = dfs(n, m, i, j+1, moves - 1);
        ll um = dfs(n, m, i-1, j, moves - 1);
        ll dm = dfs(n, m, i+1, j, moves - 1);
        
        return dp[i][j][moves] = (lm + rm + um + dm) % mod;
    }
    
    int findPaths(int n, int m, int maxMove, int startRow, int startColumn) {
        dp.resize(n+1, vector<vector<ll>> (m+1, vector<ll> (maxMove + 1, -1)));
        
        return (int)dfs(n, m, startRow, startColumn, maxMove);
    }
};














