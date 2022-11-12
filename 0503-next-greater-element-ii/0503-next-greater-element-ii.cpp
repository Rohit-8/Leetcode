class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& a) {
        
        stack<int> s;
        int n = a.size();
        
        int j = 0 , temp;
        for(int i = n - 1; i >= 0; i--)
        {
            while(!s.empty() && s.top() <= a[i])
                s.pop();
            if(s.size() > 0)
            {
                temp = s.top();
                s.push(a[i]);
                a[i] = temp;
                continue;
            }
            int flag = 0;
            
            while(i - j > 0)
            {
                if(a[j] > a[i])
                {
                    s.push(a[j]);
                    s.push(a[i]);
                    a[i] = a[j];
                    flag = 1;
                    break;
                }
                j++;
            }
            if(flag == 0)
            {
                // ans.push_back(-1);
                s.push(a[i]);
                a[i] = -1;
            }
        }
        return a;
    }
};