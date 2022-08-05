class Solution {
public:
    
    vector<vector<int>> dp;
    
    int mcm(int egg, int f){
        if(f == 1 or f == 0) return f;
        if(egg == 1) return f;
        
        if(dp[egg][f] != -1) return dp[egg][f];
        
        int res = INT_MAX;
        for(int i = 1; i <= f; i++){
            int t = 1 + max(mcm(egg-1, i-1), mcm(egg, f-i));
            
            res = min(t, res);
        }
        
        return dp[egg][f] = res;
    }
    
    int twoEggDrop(int n) {
        dp.resize(3, vector<int> (n + 1, -1));
        
        return mcm(2, n);
    }
};