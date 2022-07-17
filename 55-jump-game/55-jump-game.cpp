class Solution {
public:
    
    int dp[100001];
    int res(vector<int>& a, int n){
        if(n == a.size()) return 1;
        
        if(a[n] == 0) return 0;
        
        if(dp[n] != -1) return dp[n];
        
        int s = 0;
        for(int i = 1; i <= a[n]; i++){
            if(n + i + 1 >= a.size()) return dp[n] = 1;
            if(res(a, n+i)) return dp[n] = 1;
        }
        
        return dp[n] = 0;
    }
    
    bool canJump(vector<int>& a) {
        if(a.size()== 1) return true;
        
        memset(dp, -1, sizeof(dp));
        
        return res(a, 0);
    }
};