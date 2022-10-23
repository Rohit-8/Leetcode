class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long res = 0;
        bool mnf = false, mxf = false;
        int start = 0, mnstrt = 0, mxstrt = 0;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (num < minK or num > maxK) {
                mnf = false;
                mxf = false;
                start = i+1;
            }
            if (num == minK) {
                mnf = true;
                mnstrt = i;
            }
            if (num == maxK) {
                mxf = true;
                mxstrt = i;
            }
            if (mnf && mxf) {
                res += (min(mnstrt, mxstrt) - start + 1);
            }
        }
        return res;
    }
};