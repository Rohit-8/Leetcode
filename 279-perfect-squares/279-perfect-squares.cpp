class Solution {
public:
    int dp[10001];
    int res(int n){
        if(n <= 0) return 0;
        
        int ans = INT_MAX;
        
        if(dp[n] != -1) return dp[n];
        
        for(int i = 1; i*i <= n and n > 0; i++){
            int x = i * i;
            ans = min(ans,1 + res(n - x));
        }
        return dp[n] = ans;
    }
    
    int numSquares(int n) {
        memset(dp, -1, sizeof(dp));
        return res(n );
    }
};