class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') st.push(s[i]);
            else if(s[i] == ')') st.pop();
            ans = max(ans, (int)st.size());
        }
        
        return ans;
    }
};