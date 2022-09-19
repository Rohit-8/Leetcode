class Solution {
public:
    string removeKdigits(string s, int k) {
        if(k >= s.size()) return "0";
        stack<char> st;
        int i;
        for(i = 0; i < s.size(); i++){
            while(k > 0 and !st.empty() and st.top() > s[i])
                st.pop(), k--;
            if(st.size() == 0){
                if(s[i] == '0') continue;
            }
            st.push(s[i]);
        }
        while(k > 0 and !st.empty())
        {
            st.pop();
            k--;
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        
        
        
        reverse(begin(ans), end(ans));
        if(ans.size() == 0)
            ans += '0';
        return ans;
    }
};