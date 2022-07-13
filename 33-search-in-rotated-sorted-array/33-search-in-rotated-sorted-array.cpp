class Solution {
public:
    int search(vector<int>& a, int t) {
        int n = a.size();
        int l = 0, r = n-1;
        
        int pivot = 0;
        
        while(l <= r){
            int mid = l + (r-l)/2;
            if(a[mid] > a[r]) l = mid+1;
            else if(a[mid] < a[r]) r = mid;
            else break;
        }
        pivot = r;
        
        int ans = -1;
        if(pivot > 0 and a[pivot-1] >= t and a[0] <= t)
            l = 0, r = pivot-1;
        else l = pivot , r = n-1;
        
        while(l <= r){
            int mid = l + (r-l)/2;
            if(t > a[mid]) l = mid+1;
            else if(t < a[mid]) r = mid-1;
            else {
                ans = mid; break;
            }
        }
        
        return ans;
    }
};