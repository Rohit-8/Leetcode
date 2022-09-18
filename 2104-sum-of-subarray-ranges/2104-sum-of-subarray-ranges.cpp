#define ll long long
class Solution {
public:
    // long long mod = 1000000007;
    ll res(vector<int>& a) {
        stack<int> st;
        ll n = a.size();
        ll left[n], right[n];
        
        for(int i = 0; i < n; i++){
            while(!st.empty() and a[st.top()] > a[i])
                st.pop();
            
            if(st.empty()) left[i] = -1;
            else left[i] = st.top();
            
            st.push(i);
        }
        while(!st.empty()) st.pop();
        // cout<<st.size()<<endl;
        
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() and a[st.top()] >= a[i])
                st.pop();
            
            if(st.empty()) right[i] = n;
            else right[i] = st.top();
            
            st.push(i);
        }
        long long ans = 0;
        for(int i = 0; i < n; i++){
            ans += (((a[i] * (i - left[i])*1ll *(right[i] - i))));
            // cout<<i - left[i]<<" "<<right[i] - i<<endl;
        }
        
        return ans;
    }
    
    ll resm(vector<int>& a) {
        stack<int> st;
        ll n = a.size();
        ll left[n], right[n];
        
        for(int i = 0; i < n; i++){
            while(!st.empty() and a[st.top()] < a[i])
                st.pop();
            
            if(st.empty()) left[i] = -1;
            else left[i] = st.top();
            
            st.push(i);
        }
        while(!st.empty()) st.pop();
        // cout<<st.size()<<endl;
        
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() and a[st.top()] <= a[i])
                st.pop();
            
            if(st.empty()) right[i] = n;
            else right[i] = st.top();
            
            st.push(i);
        }
        long long ans = 0;
        for(int i = 0; i < n; i++){
            ans += (((a[i] * (i - left[i])*1ll *(right[i] - i))));
            // cout<<i - left[i]<<" "<<right[i] - i<<endl;
        }
        
        return ans;
    }
    
    long long subArrayRanges(vector<int>& a) {
        ll x = res(a);
        ll y = resm(a);
        
        return y - x;
    }
};