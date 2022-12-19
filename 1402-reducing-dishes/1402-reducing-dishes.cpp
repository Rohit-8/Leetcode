class Solution {
public:
    int res(vector<int> &a, int n, int k, vector<vector<int>> &dp){
        if(n >= a.size())
            return 0;
        
        if(dp[n][k] != -1)
            return dp[n][k]; 
        
        int sum = res(a, n + 1, k, dp);
        sum = max(sum, (k + 1) * a[n] + res(a, n + 1, k + 1, dp));
        
        return dp[n][k] = sum;
    }
    int maxSatisfaction(vector<int>& a) {
        sort(a.begin(), a.end());
        vector<vector<int>> dp(a.size() + 1, vector<int> (a.size() + 1, -1));
        return res(a, 0, 0, dp);
    }
};