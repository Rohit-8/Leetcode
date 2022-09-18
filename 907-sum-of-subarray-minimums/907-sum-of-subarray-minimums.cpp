class Solution {
public:
    long long mod = 1000000007;
    int sumSubarrayMins(vector<int>& a) {
        stack<int> st;
        long long int n = a.size();
        long long int left[n], right[n];
        
        for(int i = 0; i < n; i++){
            while(!st.empty() and a[st.top()] > a[i])
                st.pop();
            
            if(st.empty()) left[i] = -1;
            else left[i] = st.top();
            
            st.push(i);
        }
        while(!st.empty()) st.pop();
        cout<<st.size()<<endl;
        
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() and a[st.top()] >= a[i])
                st.pop();
            
            if(st.empty()) right[i] = n;
            else right[i] = st.top();
            
            st.push(i);
        }
        long long ans = 0;
        for(int i = 0; i < n; i++){
            ans += (((a[i] * (i - left[i])*1ll *(right[i] - i)) % mod)) % mod;
            cout<<i - left[i]<<" "<<right[i] - i<<endl;
        }
        
        return ans % mod;
    }
};