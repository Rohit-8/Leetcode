class Solution {
public:
    long long appealSum(string s) {
        long long ans = 0, n = s.size();
        
        map<char, int> mp;
        for(long long i = 0; i < n; i++){
            if(mp.count(s[i])){
                long long x = n - i;
                x *= (i - mp[s[i]]);
                ans += x;
                mp[s[i]] = i;
            }
            else {
                long long x = n - i;
                x *= (i + 1);
                ans += x;
                mp[s[i]] = i;
            }
        }
        
        return ans;
    }
};