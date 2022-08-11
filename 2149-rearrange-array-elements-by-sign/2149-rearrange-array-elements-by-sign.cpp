class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
		int pi = 0, ni = 1;
		for(int i = 0; i < nums.size(); i++){
			if(nums[i] > 0){
				res[pi] = nums[i];
				pi += 2;
			}
			else{
				res[ni] = nums[i];
				ni += 2;
			}
		}
		return res;
    }
};