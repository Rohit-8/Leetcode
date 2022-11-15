class Solution {
public:
    int countDistinct(vector<int>& a, int k, int p) {
        set<vector<int>> st;
        int ans = 0;
        for(int i = 0; i < a.size(); i++){
            vector<int> v;
            int c = 0;
            for(int j = i; j < a.size(); j++){
                if(a[j] % p == 0)
                    c++;
                if(c > k) break;
                v.push_back(a[j]);
                st.insert(v);
            }
        }
        
        return st.size();
    }
};