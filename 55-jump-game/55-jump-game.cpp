class Solution {
public:
    int n;
    vector<int> v;
    int res(vector<int> &a, int k){
        if(k >= n - 1) return 1;
        if(a[k] == 0) return 0;
        
        if(v[k] != -1) return v[k];
        
        int f = 0;
        for(int i = 1; i <= a[k]; i++){
            if(k + i >= n - 1) return v[k] = 1;
            f |= res(a, k + i);
            if(f) return v[k] = 1;
        }
        
        return v[k] = f;
    }
    bool canJump(vector<int>& a) {
        n = a.size();
        v.resize(n + 1, -1);
        return res(a, 0);
    }
};