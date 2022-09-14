class Solution {
public:
    int minGroups(vector<vector<int>>& a) {
        sort(a.begin(), a.end());
        
        priority_queue<int,vector<int>,greater<int>> pq;
        pq.push(a[0][1]);
        
        for(int i = 1; i < a.size(); i++){
            if(a[i][0] <= pq.top())
                pq.push(a[i][1]);
            
            else{
                pq.pop();
                pq.push(a[i][1]);
            }
        }
        
        return pq.size();
    }
};