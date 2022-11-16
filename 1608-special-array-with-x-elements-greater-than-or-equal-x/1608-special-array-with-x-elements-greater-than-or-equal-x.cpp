class Solution {
public:
    int res(vector<int> &a, int x){
        int ans = 0;
        for(int i = 0; i < a.size(); i++){
            if(a[i] >= x)
                ans++;
        }
        return ans;
    }
    int specialArray(vector<int>& nums) {
        int l = 0, r = 10000;
        while(l <= r){
            int mid = (l + r) / 2;
            int x = res(nums, mid);
            
            if(x == mid){
                return mid;
            }
            else if(x > mid){
                l = mid + 1;
            }
            else r = mid - 1;
        }
        
        return -1;
    }
};