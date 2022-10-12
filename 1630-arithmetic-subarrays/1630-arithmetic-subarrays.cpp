class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& a, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        
        for(int j = 0; j < l.size(); j++){
            vector<int> v;
            for(int i = l[j]; i <= r[j]; i++){
                v.push_back(a[i]);
            }
            
            sort(v.begin(), v.end());
            int diff = v[1] - v[0];
            bool f = true;
            for(int i = 2; i < v.size(); i++){
                if(v[i] - v[i - 1] != diff){
                    f = false; break;
                }
            }
            ans.push_back(f);
        }
        
        return ans;
    }
};