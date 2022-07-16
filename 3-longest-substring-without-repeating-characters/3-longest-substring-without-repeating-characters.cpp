class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        unordered_map<char, int> m;
        
        int j = 0;
        for(int i = 0; i < s.size(); i++){
            int n = m.size();
            m[s[i]] = 1;
            if(n == m.size()){
                while(j < i and s[j] != s[i]){
                    m.erase(s[j]);
                    j++;
                }
                j++;
            }
            
            m[s[i]] = 1;
            ans = max(ans, (int)m.size());
        }
        return ans;
    }
};