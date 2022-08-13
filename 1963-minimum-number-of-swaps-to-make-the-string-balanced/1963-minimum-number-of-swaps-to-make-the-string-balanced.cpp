class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ']' and st.size() and st.top() == '['){
                st.pop();
            }
            else st.push(s[i]);
        }
        
        return (st.size() / 2) / 2 + (st.size() / 2) % 2;
    }
};