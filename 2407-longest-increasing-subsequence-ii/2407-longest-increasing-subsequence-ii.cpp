class Solution {
public:
    /*
        The number that can be behind number X is in the range [X - k, X - 1], and the best value for the LIS than ends with X is the maximum value in that range + 1, 1 for the current element X.
So we use a segment tree to find the maximum value in the range and update the current value for further use and calculate the result with every iteration.
    */
    
    // Here we are using elements as indexes of segment tree and its count(that is till now who are meeting condition till this number) as value of segment tree.
    vector<int> seg;
    //Segment tree to return maximum in a range
    void upd(int i, int val, int ind, int low, int high) {
        if(low == high) {
            seg[ind] = val;
            return;
        }
        int mid = low + (high - low) / 2;
        if(i <= mid)
            upd(i, val, 2 * ind + 1, low, mid);
        else 
            upd(i, val, 2 * ind + 2, mid + 1, high);
        seg[ind] = max(seg[2 *ind + 1], seg[2 * ind + 2]);
    }
    
    int query(int l, int r, int ind, int low, int high) {
        // no overlap
        if(low > r or high < l) return 0;
        // complete overlap
        if(low >= l and high <= r) return seg[ind];
        // partial overlap
        int mid = low + (high - low) / 2;
        return max(query(l, r, 2 * ind + 1, low, mid), query(l, r, 2 * ind + 2, mid + 1, high));
    }
    
    int lengthOfLIS(vector<int>& nums, int k) {
        int x = 1;
        while(x <= 200000) x *= 2;
        seg.resize(2 * x, 0);
        
        int res = 1;
        for(int i = 0; i < nums.size(); ++i) {
            int left = max(1, nums[i] - k), right = nums[i] - 1;
            int q = query(left, right, 0, 0, x - 1); // check for the element in the range of [nums[i] - k, nums[i] - 1] with the maximum value
            // cout <<nums[i] <<" " << q << endl;
            res = max(res, q + 1);
            upd(nums[i], q + 1, 0, 0, x - 1); //update current value
        }
        return res;
    }
};