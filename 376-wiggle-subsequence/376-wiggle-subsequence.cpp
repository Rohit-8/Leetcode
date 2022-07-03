class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        int  c = 1, d = 1;
        for(int i = 1; i < nums.size(); i++){
            
            if(nums[i] > nums[i-1]) d = c+1;
            else if(nums[i]<nums[i-1]) c = d+1;
        }
        return max(d,c);
    }
};