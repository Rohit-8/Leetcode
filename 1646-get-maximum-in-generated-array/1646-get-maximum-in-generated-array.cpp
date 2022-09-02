class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n == 0) return 0;
        vector<int> a(n + 1, 0);
        a[1] = 1;
        int mx = 1;
        for(int i = 2; i <= n; i++){
            if(i % 2 == 0){
                a[i] = a[i/2];
                mx = max(a[i], mx);
            }
            else {
                a[i] = a[i/2] + a[(i/2 + 1)];
                mx = max(a[i], mx);
            }
        }
        
        return mx;
    }
};