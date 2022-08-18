class Solution {
public:
    int mod = 1000000007;
    
    int rangeSum(vector<int>& a, int n, int l, int r) {
        // int n = a.size();
        int m = n * (n + 1) / 2;
        vector<int> pre(m, 0);
        int k = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(j == i) pre[k++] = a[j];
                else pre[k] = (pre[k-1] + a[j]) % mod, k++;
            }
        }
        
        sort(begin(pre), end(pre));
        l--, r--;
        int ans = 0;
        for(int i = l; i <= r; i++){
            ans = (ans + pre[i]) % mod;
            cout<<pre[i]<<" ";
        }
        
        return ans;
    }
};