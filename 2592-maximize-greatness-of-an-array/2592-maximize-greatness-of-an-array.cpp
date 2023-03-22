class Solution {
public:
    int maximizeGreatness(vector<int>& v) {
        // vector<int> v = a;
        sort(v.begin(), v.end());
        int ans = 0, k = 0;
        for(int i = 0; i < v.size() and k < v.size(); i++){
            int x = lower_bound(v.begin() + k, v.end(), v[i] + 1) - v.begin();
            if(x < v.size()) ans++, k = x + 1;
            else k = v.size() + 1;
        }
        
        return ans;
    }
};