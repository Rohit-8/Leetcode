class Solution {
public:
    int firstMissingPositive(vector<int>& a) {
        int ans = 1;
        int n = a.size();
        
        for(int i = 0; i < n; i++){
            if(a[i] == 1) ans = 0;
            if(a[i] <= 0 or a[i] > n) a[i] = 1;
        }
        if(ans) return ans;
        
        for(int i = 0; i < n; i++){
            if(a[abs(a[i])-1] > 0)
            a[abs(a[i])-1]*= -1;   
        }
        
        for(int i = 0; i < n; i++){
            if(a[i] > 0) return i+1;
        }
        
        return n+1;
    }
};