class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        vector<int> v;
        v.push_back(a[0]);
        
        for(int i = 0; i< a.size(); i++){
            if(a[i]> v[v.size()-1])
                v.push_back(a[i]);
            
            else {
                int x = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
                v[x] = a[i];
            }
        }
        
        return v.size();
        
    }
};