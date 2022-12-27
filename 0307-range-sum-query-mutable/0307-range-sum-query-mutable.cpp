class NumArray {
public:
    vector<int> seg;
    int n;
    
    void build(int ind, int low, int high, vector<int> &arr){
        if(low == high){
            seg[ind] = arr[low];
            return;
        }
        int mid = low + (high - low) / 2;
        
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
    
    int query(int ind, int low, int high, int l, int r){
        // no overlap
        if(r < low or l > high)
            return 0;
        // complete overlap
        if(l <= low and r >= high)
            return seg[ind];
        // partial overlap
        int mid = low + (high - low) / 2;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        
        return left + right;
    }
    
    void updatep(int ind, int low, int high, int i, int val){
        if(low == high){
            seg[ind] = val;
            return;
        }
        int mid = low + (high - low) / 2;
        if(i <= mid)
            updatep(2 * ind + 1, low, mid, i, val);
        else
            updatep(2 * ind + 2, mid + 1, high, i, val);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
    
    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(4 * n + 1, 0);
        build(0, 0, n - 1, nums);
    }
    
    void update(int index, int val) {
        updatep(0, 0, n - 1, index, val);
    }
    
    int sumRange(int left, int right) {
        return query(0, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */