class Solution {
public:
    int solve(vector<int> &a, int k){
        int ans = 0;
        int i = 0, j = 0;
        int n = a.size();
        
        unordered_map<int, int> mp;
        for(; i < n; i++){
            mp[a[i]]++;
            while(mp.size() > k){
                mp[a[j]] --;
                if(mp[a[j]] == 0)
                    mp.erase(a[j]);
                j++;
            }
            ans += i - j + 1;
        }
        
        return ans;
    }
    
    int subarraysWithKDistinct(vector<int>& a, int k) {
        return solve(a, k) - solve(a, k - 1);
    }
};