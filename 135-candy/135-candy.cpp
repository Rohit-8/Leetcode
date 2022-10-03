class Solution {
public:
    int candy(vector<int>& a) {
        int n = a.size();
        vector<int> v(n, 1);
        for(int i = 1; i < n; i++){
            if(a[i] > a[i - 1])
                v[i] = v[i - 1] + 1;
        }
        for(int i = n - 2; i >= 0; i--){
            if(a[i] > a[i + 1]){
                v[i] = max(v[i], v[i + 1] + 1);
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += v[i];
        }
        
        return ans;
    }
};