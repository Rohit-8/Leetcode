class Solution {
public:
    vector<int> dp;
    int res(int n){
        if(n <= 2) return n;
        if(dp[n] != -1) return dp[n];
        return dp[n] = res(n-1) + res(n-2);
    }
    
    int climbStairs(int n) {
        dp.resize(n + 1, -1);
        return res(n);
    }
};