class Solution {
public:
    vector<int> dp;
    bool res(vector<int> &a, int i){
        if(i >= a.size()) return true;
        if(dp[i] != -1)
            return dp[i];
        
        bool f = false;
        if(i + 1 < a.size() and a[i] == a[i + 1])
            f |= res(a, i + 2);
        if(i + 2 < a.size() and a[i] == a[i + 1] and a[i] == a[i + 2])
            f |= res(a, i + 3);
        else if(i + 2 < a.size() and a[i] == a[i + 1] - 1 and a[i] == a[i + 2] - 2)
            f |= res(a, i + 3);
        return dp[i] = f;
    }
    
    bool validPartition(vector<int>& a) {
        dp.resize(a.size() + 1, -1);
        return res(a, 0);
    }
};