class Solution {
public:
    int merge(vector<int> &a, int l, int mid, int r){
        int c = 0, j = mid + 1;
        for(int i = l; i <= mid; i++){
            while(j <= r and a[i] > 2ll * a[j])
                j ++;
            c += j-mid-1;
        }
        
        vector<int> t;
        int left = l, right = mid + 1;
        while(left <= mid and right <= r){
            if(a[left] <= a[right])
                t.push_back(a[left++]);
            else t.push_back(a[right++]);
        }
        
        while(left <= mid) t.push_back(a[left++]);
        while(right <= r) t.push_back(a[right++]);
        
        for(int i = l; i <= r; i++)
            a[i] = t[i - l];
        
        return c;
    }
    int mergesort(vector<int> &a, int l , int r){
        if(l >= r) return 0;
        
        int mid = l + (r-l)/2;
        int inv = mergesort(a, l, mid);
        inv += mergesort(a, mid+1, r);
        inv += merge(a, l, mid, r);
        
        return inv;
    }
    
    int reversePairs(vector<int>& a) {
        return mergesort(a, 0, a.size()-1);
    }
};