class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& a) {
        vector<int> ans;
        stack<int> s;
        int n = a.size();
        // vector<int> r;
        
        for(int i = 0; i < n; i++){
            a.push_back(a[i]);
        }
        int j = 0;
        for(int i = n + n - 1; i >= n; i--)
        {
            while(!s.empty() && s.top() <= a[i])
                s.pop();
            if(s.size() > 0)
            {
                ans.push_back(s.top());
                s.push(a[i]);
                continue;
            }
            int flag = 0;
            
            while(i - j > n)
            {
                if(a[j] > a[i])
                {
                    ans.push_back(a[j]);
                    s.push(a[j]);
                    s.push(a[i]);
                    flag = 1;
                    break;
                }
                j++;
            }
            if(flag == 0)
            {
                ans.push_back(-1);
                s.push(a[i]);
            }
        }
//         for(int i = n + n - 1; i >= 0; i--){
//             while(!st.empty() and st.top() <= a[i])
//                 st.pop();
            
//             if(st.empty())
//                 r.push_back(-1);
//             else r.push_back(st.top());
//             st.push(a[i]);
//         }
//         reverse(begin(r), end(r));
        
        // for(int i = 0; i < n; i++){
        //     if(r[i] != -1) ans.push_back(r[i]);
        //     else ans.push_back(-1);
        // }
        reverse(ans.begin() , ans.end());
        
        return ans;
    }
};