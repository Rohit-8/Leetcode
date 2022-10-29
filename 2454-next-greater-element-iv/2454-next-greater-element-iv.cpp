class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& a) {
        vector<int> ans(a.size(), -1);
        
        deque<int> q1;
		
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q2;
        
        int n = a.size();
        for (int i = 0; i < n; ++i) {
            while (!q2.empty() && q2.top().first < a[i]) {
                ans[q2.top().second] = a[i];
                q2.pop();
            }
    
            while (!q1.empty() && a[q1.back()] < a[i]) {
                q2.push({a[q1.back()], q1.back()});
                q1.pop_back();
            }
            
            q1.push_back(i);
        }
        
        return ans;
    }
};