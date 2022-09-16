class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();

        int count = 0;
        for(int i = 0; i < n; i++){
            if(mp.find(nums[i]) != mp.end()){
                for(auto x : mp[nums[i]])
                    if((i * x) % k == 0)
                        count++;
            }
            mp[nums[i]].push_back(i);
        }
        return count;
    }
};