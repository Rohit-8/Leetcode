class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<char> st;
        int ans = 0;
        
        for(int i = 0, j = 0; i < n; i++){
            int x = st.size();
            st.insert(s[i]);
            
            if(x == st.size()){
                while(j < i and s[j] != s[i]){
                    st.erase(s[j]);
                    j++;
                }
                j++;
            }
            ans = max(ans, (int)st.size());
        }
        return ans;
    }
};