class Solution {
public:
    int minimumCardPickup(vector<int>& a) {
        map<int, int> mp;
        
        int ans = INT_MAX;
        for(int i = 0; i < a.size(); i++){
            if(mp.count(a[i])){
                ans = min(ans, i - mp[a[i]] + 1);
            }
            mp[a[i]] = i;
        }
        if(ans != INT_MAX)
            return ans;
        
        return -1;
    }
};