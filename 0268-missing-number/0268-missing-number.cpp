class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xor1 =0, xor2 =0;
        for(int i=0;i<n;i++)
        {
            xor1 = xor1^(i+1);
        }
        for(int j=0;j<n;j++)
            xor2 = xor2^nums[j];

        return xor1^xor2;
    }
};