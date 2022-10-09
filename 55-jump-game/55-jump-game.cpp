class Solution {
public:
    vector<int> dp;
    bool fl = false;
    int res(vector<int> &a, int n){
        
        if(n >= a.size() - 1) return 1;
        if(fl) return 1;
        if(dp[n] != -1) return dp[n];
        int f = 0;
        for(int i = 1; i <= a[n] and a[n] > 0; i++){
            f |= res(a, i + n);
            if(f) break;
        }
        if(f) fl = true;
        return dp[n] = f;
    }
    bool canJump(vector<int>& a) {
        dp.resize(a.size() + 1, -1);
        return res(a, 0);
    }
};