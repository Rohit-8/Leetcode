class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int l = *min_element(nums.begin(),nums.end());
        int r = *max_element(nums.begin(),nums.end());
        long long ans = 1e18;
        while (r >= l) {
            long long mid1 = l + (r - l) / 3;
            long long mid2 = r - (r - l) / 3;
            
            long long a1 = 0, a2 = 0;
            
            for(int i=0;i<nums.size();i++){
                a1 += (abs(mid1 - nums[i]) * cost[i]);
                a2 += (abs(mid2 - nums[i]) * cost[i]);
            }
            
            if(a1 < a2) r = mid2-1;
            else l = mid1+1;
			ans = min({ans,a1,a2});
        }
        return ans;
    }
};