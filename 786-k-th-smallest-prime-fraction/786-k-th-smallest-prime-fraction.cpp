class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        
        priority_queue<pair<double, pair<int,int>>> pq;
        for(int i = 0; i < arr.size(); i++)
            for(int j = i+1; j < arr.size(); j++){
                
                double t = (double)arr[i]/ arr[j];
                pq.push({t, { arr[i], arr[j]} });
                if(pq.size() > k)
                    pq.pop();
            }
        
        return {pq.top().second.first, pq.top().second.second};
    }
};