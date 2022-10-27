class Solution {
public:
    void res(vector<int> &nums, vector<int> v, vector<vector<int>> &ans, map<int, int> m){
        if(v.size() >= nums.size()){
            ans.push_back(v);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(m[nums[i]] <= 0){
                m[nums[i]] ++;
                v.push_back(nums[i]);
                res(nums, v, ans, m);
                v.pop_back();
                m[nums[i]] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        map<int,int> m;
        res(nums, v, ans, m);
        
        return ans;
    }
};