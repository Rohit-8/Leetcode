class Solution {
public:
    bool res(vector<int> &a, int x, int k){
        int c = 1;
        int prev = a[0];
        for(int i = 1; i < a.size(); i ++){
            if(a[i] - prev >= x)
                c++, prev = a[i];
            if(c >= k)
                return true;
        }
        return c >= k;
    }
    
    int maximumTastiness(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        
        int l = 0, r = 1e9 + 1;
        int ans = 0;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(res(a, mid, k))
                ans = max(ans, mid), l = mid + 1;
            else r = mid - 1;
        }
        
        return ans;
    }
};