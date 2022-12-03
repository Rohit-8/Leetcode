class Solution {
public:
    int gcd(int a, int b){
        return b == 0 ? a : gcd(b, a % b);    
    }
    vector<int> replaceNonCoprimes(vector<int>& a) {
        vector<int> ans;
        stack<int> st;
        for(int i = 0; i < a.size(); i++){
            st.push(a[i]);
            while(st.size() > 1){
                long x = st.top();
                st.pop();
                long y = st.top();
                if(gcd(x, y) > 1){
                    st.pop();
                    st.push((x * y * 1ll) / gcd(x, y));
                }
                else {
                    st.push(x);
                    break;
                }
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};