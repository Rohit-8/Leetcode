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
            long long x = min(r[i] - l[i] -1, 1ll*arr[i]);
            ans = max(ans, x*x);
            
        }
        
        return ans;
    }
    
    int maximalSquare(vector<vector<char>>& a) {
        int n = a.size(), m = a[0].size();
        vector<vector<int>> h(n, vector<int> (m, 0));
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j< m; j++){
                if(i > 0 and a[i][j] == '1') h[i][j] = h[i-1][j] + 1;
                else if(a[i][j] == '1' and i == 0) h[i][j] = 1;
            }
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            int x = largestRectangleArea(h[i]);
            ans = max(ans, x);
        }
        
        return ans;
    }
};