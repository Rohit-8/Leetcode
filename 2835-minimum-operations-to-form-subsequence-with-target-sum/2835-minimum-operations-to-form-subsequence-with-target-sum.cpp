class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        int cnt[32] = {};
        int j = 32, op = 0;
        
        for(auto x: nums){
            cnt[(int)log2(x)] ++;
        }
        
        for(int i = 0; i < 31; i++){
            int bit = 1 << i;
            if((target & bit) == bit){
                // cout << bit << endl;
                if(cnt[i] == 0)
                    j = min(j, i);
                else cnt[i]--;
            }
            if(cnt[i] and j < i){
                op += i - j;
                j = 32;
                cnt[i]--;
            }
            cnt[i + 1] += cnt[i] / 2;
        }
        
        return j < 32 ? -1 : op;
    }
};