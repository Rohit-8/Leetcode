class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int sum1 = 0, sum2 = 0;
        for(int i = 0; i < nums1.size(); i++){
            sum1 += nums1[i];
            sum2 += nums2[i];
        }
        
        int f = 0, s = 0, mx1 = 0, mx2 = 0;
        for(int i = 0; i < nums1.size(); i++){
            s = max(s + nums1[i] - nums2[i], nums1[i] - nums2[i]);
            f = max(f + nums2[i] - nums1[i], nums2[i] - nums1[i]);
            
            mx1 = max(mx1, f);
            mx2 = max(mx2, s);
        }
        int ans = max({sum1, sum2, sum1 + mx1, sum2 + mx2});
        return ans;
    }
};