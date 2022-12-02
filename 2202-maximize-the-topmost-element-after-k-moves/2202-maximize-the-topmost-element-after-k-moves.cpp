class Solution {
public:
    int maximumTop(vector<int>& a, int k) {
        if(k % 2 and a.size() == 1) return -1;
        int ans = -1, mx = -1, i;
        for(i = 0; i < min(k, (int)a.size()); i++){
            ans = max(ans, mx);
            mx = max(mx, a[i]);
        }
        if(i < k) ans = max(ans, mx);
        if(i < a.size()) ans = max(ans, a[i]);
        return ans;
    }
};