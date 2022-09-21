class Solution {
public:
    int findPeakElement(vector<int>& a) {
        int n = a.size();
        if(n == 1) return 0;
        if(a[0] > a[1]) return 0;
        if(a[n - 1] > a[n - 2]) return n - 1;
        
        int l = 1, r = n - 2;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(mid == 0 and a[mid] > a[mid + 1]) return mid;
            if(mid == n - 1 and a[mid] > a[mid - 1]) return mid;
            if(a[mid] > a[mid - 1] and a[mid] > a[mid + 1]) return mid;
            if(a[mid] > a[mid - 1] and a[mid] < a[mid + 1])
                l = mid + 1;
            else r = mid - 1;
        }
        
        return 0;
    }
};