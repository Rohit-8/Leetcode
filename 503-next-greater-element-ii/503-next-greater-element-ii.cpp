class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& a) {
        vector<int> ans;
        stack<int> st;
        int n = a.size();
        vector<int> r;
        for(int i = 0; i < n; i ++){
            a.push_back(a[i]);
        }
        for(int i = n + n - 1; i >= 0; i--){
            while(!st.empty() and st.top() <= a[i])
                st.pop();
            
            if(st.empty())
                r.push_back(-1);
            else r.push_back(st.top());
            st.push(a[i]);
        }
        reverse(begin(r), end(r));
        
        for(int i = 0; i < n; i++){
            if(r[i] != -1) ans.push_back(r[i]);
            else ans.push_back(-1);
        }
        
        return ans;
    }
};