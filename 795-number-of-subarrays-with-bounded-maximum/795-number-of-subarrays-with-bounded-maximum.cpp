class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& a, int l, int r) {
        int n = a.size();
        int ans = 0;
        int mx = 0;
        
        for(int i = 0, j = 0; i < n and j < n; j++){
            if(a[j] > r){
                mx = 0; i = j + 1;
                continue;
            }
            if(a[j] <= r and a[j] >= l){
                mx = j - i + 1;
                ans += mx;
            }
            else{
                ans += mx;
            }
            
        }
        
        return ans;
    }
};