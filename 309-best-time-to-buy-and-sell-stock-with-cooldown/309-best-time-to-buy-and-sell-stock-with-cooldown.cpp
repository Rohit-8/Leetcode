class Solution {
public:
    
    vector<vector<int>> dp;
    int res(vector<int> &a, int n, int buy){
        
        if(n >= a.size()) return 0;
        
        if(dp[n][buy] != -1) return dp[n][buy];
        int sum = 0;
        if(buy == 1){
            sum += max(-a[n] + res(a, n+1, 0), res(a, n+1, 1));
        }
        else{
            sum += max(a[n] + res(a, n+2, 1), res(a, n+1, 0));
        }
        return dp[n][buy] = sum;
    }
    
    int maxProfit(vector<int>& a) {
        
        int n = a.size();
        dp.resize(n+1, vector<int> (2, -1));
        
        return res(a, 0, 1);
    }
};