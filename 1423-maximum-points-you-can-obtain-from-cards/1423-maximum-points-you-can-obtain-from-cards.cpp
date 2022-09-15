class Solution {
public:
    int maxScore(vector<int>& a, int k) {
        int n = a.size();
        vector<int> pre(n + 1, 0);
        vector<int> suff(n + 1, 0);
        
        pre[0] = 0;
        suff[n] = 0;
        for(int i = 1; i <= n; i++)
            pre[i] = pre[i - 1] + a[i - 1];
        
        suff[n - 1] = a[n - 1];
        for(int i = n - 2; i >= 0; i--)
            suff[i] = suff[i + 1] + a[i];
        
        int ans = 0;
        for(int i = 0; i <= k; i++){
            ans = max(ans, pre[k - i] + suff[n - i]);
        }
        
        return ans;
    }
};