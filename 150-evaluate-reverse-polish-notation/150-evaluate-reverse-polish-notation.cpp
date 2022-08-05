class Solution {
public:
    int evalRPN(vector<string>& a) {
        stack<int> st;
        for(int i = 0; i < a.size(); i++){
            if(a[i] == "*"){
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                st.push(x*y);
                continue;
            }
            if(a[i] == "/"){
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                st.push(y/x);
                continue;
            }
            if(a[i] == "-"){
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                st.push(y-x);
                continue;
            }
            if(a[i] == "+"){
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                st.push(x+y);
                continue;
            }
            st.push(stoi(a[i]));
        }
        return st.top();
    }
};