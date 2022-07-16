class Solution {
public:
    vector<int> twoSum(vector<int>& a, int t) {
        unordered_map<int,int> m;
        
        for(int i = 0; i < a.size(); i++){
            if(m.find(t-a[i]) != m.end()){
                return {i, m[t-a[i]]};
            }
            m[a[i]] = i;
        }
        
        return {};
    }
};