class Solution {
public:
    vector<int> searchRange(vector<int>& a, int t) {
        int n = a.size();
        int l = 0, r = n-1;
        int st = -1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(a[mid] > t) r = mid-1;
            else if(a[mid] < t) l = mid+1;
            else st = mid, r = mid-1;
        }
        l = 0, r = n-1;
        int end = -1;
        while(l <= r){
            int mid = l + (r-l)/2;
            
            if(a[mid] > t) r = mid-1;
            else if(a[mid] < t) l = mid+1;
            else end = mid, l = mid+1;
        }
        
        return {st, end};
    }
};