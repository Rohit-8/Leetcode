class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        map<int, vector<int> > m;
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = nums[i]; j > 0; j /= 10){
                sum += (j % 10);
            }
            m[sum].push_back(nums[i]);
        }
        int ans = -1;
        for(auto x: m){
            if(x.second.size() > 1){
                n = x.second.size();
                sort(x.second.begin(), x.second.end());
                ans = max(ans, x.second[n - 1] + x.second[n - 2]);
            }
        }
        
        return ans;
    }
};