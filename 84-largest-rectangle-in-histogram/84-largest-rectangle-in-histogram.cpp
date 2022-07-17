class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        
        long long ans = 0;
        vector<long long> r,l;
        stack<long long> s;
        int n = arr.size();
        for(long long i = 0; i< n; i++){
            
            while(!s.empty() and arr[s.top()] >= arr[i]) s.pop();
            
            if(s.empty()) l.push_back(-1);
            else l.push_back(s.top());
            s.push(i);
        }
        while(!s.empty()) s.pop();
        
        for(long long i = n-1; i>=0; i--){
            
            while(!s.empty() and arr[s.top()] >= arr[i]) s.pop();
            
            if(s.empty()) r.push_back(n);
            else r.push_back(s.top());
            s.push(i);
        }
        reverse(r.begin(), r.end());
        // for(int i = 0; i< n;i++) cout<<r[i]<<" ";
        // cout<<endl;
        
        for(long long i = 0; i< n; i++){
            
            ans = max(ans, (r[i] - l[i] -1)*arr[i]);
            
        }
        
        return ans;
    }
};