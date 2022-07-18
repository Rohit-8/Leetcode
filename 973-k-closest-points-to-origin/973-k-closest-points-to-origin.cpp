class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& a, int k) {
        
        priority_queue<pair<double, int>> pq;
        vector<vector<int>> ans;
        int n = a.size();
        
        if (k >= n)
            return a;
        
        for (int i = 0; i < n; i++){
            
            int x = a[i][0] * a[i][0];
            int y = a[i][1] * a[i][1];
            double d = sqrt(x + y);
            
            if (pq.size() < k)
                pq.push({d, i});
            
            else{
                if (pq.top().first > d){
                    pq.pop();
                    pq.push({d, i});
                }
            }
        }
        while (!pq.empty()){
            int x = pq.top().second;
            ans.push_back(a[x]);
            pq.pop();
        }
        
        return ans;
    }
};