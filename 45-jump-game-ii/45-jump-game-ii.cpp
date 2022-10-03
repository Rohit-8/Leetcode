class Solution {
public:
    int n;
    vector<int> dp;
    
    int res(vector<int> &a, int j){
        if(j >= n - 1){
            return 0;
        }
        
        if(dp[j] != -1) return dp[j];
        if(a[j] == 0) return dp[j] = 1e9;
        
        int ans = 1e9;
        for(int i = 1; i <= a[j]; i++){
            ans = min(ans, 1 + res(a, j + i));
        }
        return dp[j] = ans;
    }
    
    int jump(vector<int>& a) {
        n = a.size();
        if(n == 1) return 0;
        dp.resize(n + 1, -1);
        res(a, 0); 
        return dp[0];
    }
};