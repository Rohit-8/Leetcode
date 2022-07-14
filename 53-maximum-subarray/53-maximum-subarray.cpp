class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int sum = 0;
        int ans = INT_MIN;
        
        for(int i = 0; i < a.size(); i++){
            sum = max(sum + a[i], a[i]);
            ans = max(ans, sum);
        }
        
        return ans;
    }
};