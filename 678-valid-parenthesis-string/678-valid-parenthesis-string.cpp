class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st, st2;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == '*'){
                st2.push(i);
            }
            else {
                if(st.size() > 0) st.pop();
                else if(st2.size() > 0) st2.pop();
                else return false;
            }
            // if(i == 29) cout<<c<<endl;
        }
        while(!st.empty()){
            if(st2.size() <= 0) return false;
            if(st.top() < st2.top()){
                st.pop(), st2.pop();
            }
            else return false;
        }
        
        return true;
    }
};