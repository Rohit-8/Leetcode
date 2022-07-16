class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        int l[n], r[n];
        
        int pre = h[0];
        for(int i = 0;i<n ; i++){
            pre = max(pre,h[i]);
            l[i] = pre;
        }
        pre = h[n-1];
        for(int i= n-1; i>=0; i--)
            pre = max(h[i], pre), r[i] = pre;
        
        int ans = 0;
        for(int i = 0; i< n; i++){
            ans += (min(l[i],r[i]) - h[i]);
        }
        
        return ans;
        
    }
};