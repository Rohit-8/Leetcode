class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int ans = 0, n = nums.size();
        for(int i = 0; i < n - 2; i++){
            for(int j = i + 1; j < n - 1; j++){
                int x = lower_bound(nums.begin(), nums.end(), nums[i] + nums[j]) - nums.begin() - j - 1;
                if(x <= 0) continue;
                
                ans += x;
            }
        }
        
        return ans;
    }
};