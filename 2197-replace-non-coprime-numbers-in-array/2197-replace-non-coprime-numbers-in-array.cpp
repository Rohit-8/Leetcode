class Solution {
public:
    int gcd(int a, int b){
        return b == 0 ? a : gcd(b, a % b);    
    }
    vector<int> replaceNonCoprimes(vector<int>& a) {
        vector<int> ans;
        stack<long long> st;
        for(int i = 0; i < a.size(); i++){
            st.push(a[i]);
            while(st.size() > 1){
                long long x = st.top();
                st.pop();
                long long y = st.top();
                if(gcd(x, y) > 1){
                    st.pop();
                    st.push((x * y) / gcd(x, y));
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
        // ans.push_back(l);
        reverse(ans.begin(), ans.end());
        cout<< gcd(899, 23);
        return ans;
    }
};