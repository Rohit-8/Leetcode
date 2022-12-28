class Solution {
public:
    int kIncreasing(vector<int>& a, int k) {
        int ans = 0;
        for(int j = 0; j < k; j ++){
            int c = 0;
            vector<int> v;
            // v.push_back(a[0]);
            for(int i = j; i < a.size(); i += k){
                c++;
                if(i == j){
                    v.push_back(a[i]);
                    continue;
                }
                if(a[i] >= v[v.size()-1])
                    v.push_back(a[i]);
                else {
                    int x = lower_bound(v.begin(), v.end(), a[i] + 1) - v.begin();
                    v[x] = a[i];
                }
            }
            ans += (c - v.size());
        }
        
        return ans;
    }
};