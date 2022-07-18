class Solution {
public:
    int minSubArrayLen(int t, vector<int>& a) {
        int ans = 1e9;
        
        int sum = 0;
        for(int i = 0, j = 0; i < a.size() or (i == a.size() and sum >= t); ){
            if(sum < t) sum += a[i++];
            else{
                ans = min(ans, i - j);
                sum -= a[j++];
            }
        }
        if(ans == 1e9) ans = 0;
        return ans;
    }
};