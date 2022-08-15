class Solution {
public:
    int romanToInt(string s) {
        int t = 0;
        int ans = 0;
        
        unordered_map<char, int> m = {{'M', 1000},{'D', 500},{'C', 100},{'L', 50},{'X', 10},{'V', 5},{'I', 1}};
        
        for (int i = 0; i < s.size(); i++){
            int x = m[s[i]];
            if (x <= t) ans += x;
            
            else{
                ans -= t;
                ans += x - t;
            }
            t = x;
        }
        
        return ans;
    }
};