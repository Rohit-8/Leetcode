class Solution {
public:
    int mctFromLeafValues(vector<int>& v) {
         int c=0;
        stack<int> st;
        for(int i:v) {
        while(!st.empty() && st.top() <= i) {
        int x = st.top();
        st.pop();
        c += x * min(st.empty() ? INT_MAX : st.top(),i);
        }
        st.push(i);
        }
        int a = st.top();
        st.pop();
        while(!st.empty()) {
        int x = st.top();
        st.pop();
        c += x * min(st.empty() ? INT_MAX : st.top(), a);
        a = x;
        }
        return c;   
    }
};
