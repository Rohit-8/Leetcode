class Solution {
public:
    int res(vector<int> &a, int n, int prev, vector<vector<int>> &dp){
        if(n >= a.size())
            return 0;
        if(dp[n][prev + 1] != -1){
            return dp[n][prev + 1];
        }
        int l = res(a, n + 1, prev, dp);
        if(prev == -1 or a[n] > a[prev]){
            l = max(1 + res(a, n + 1, n, dp), l);
        }
        
        return dp[n][prev + 1] = l;
    }
    
    int lengthOfLIS(vector<int>& a) {
        vector<vector<int>> dp(a.size() + 5, vector<int> (a.size() + 5, -1));
        return res(a, 0, -1, dp);
    }
};