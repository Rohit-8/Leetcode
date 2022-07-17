class Solution {
public:
    
    vector<vector<vector<int>>> dp;
    int res(vector<int> &a, int n, int buy, int cap){
        
        if(n >= a.size()) return 0;
        if(cap <= 0 and buy == 1) return 0;
        
        if(dp[n][buy][cap] != -1) return dp[n][buy][cap];
        int sum = 0;
        if(buy == 1){
            sum += max(-a[n] + res(a, n+1, 0, cap-1), res(a, n+1, 1, cap));
        }
        else{
            sum += max(a[n] + res(a, n+1, 1, cap), res(a, n+1, 0, cap));
        }
        return dp[n][buy][cap] = sum;
    }
    
    int maxProfit(int k, vector<int>& a) {
        int n = a.size();
        dp.resize(n+1, vector<vector<int>> (2, vector<int> (k+1, -1)));
        
        return res(a, 0, 1, k);
    }
};