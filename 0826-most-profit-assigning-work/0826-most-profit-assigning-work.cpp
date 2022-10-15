class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w){
        sort(w.begin(), w.end());
        vector<pair<int, int>> v;
        
        int prev = 0;
        for(int i = 0; i < d.size(); i++){
            v.push_back({d[i], p[i]});
        }
        
        sort(v.begin(), v.end());
        for(int i = 0; i < d.size(); i++){
            if(v[i].second > prev)
                prev = v[i].second;
            v[i].second = prev;
        }
        int ans = 0;
        
        for(int i = 0, j = 0; i < w.size(); i++){
            while(j < v.size() and v[j].first <= w[i])
                j++;
            
            if(j == 0) continue;
            j--;
            ans += v[j].second;
        }
        
        return ans;
    }
};