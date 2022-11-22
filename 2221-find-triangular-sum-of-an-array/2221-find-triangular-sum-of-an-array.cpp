class Solution {
public:
    int triangularSum(vector<int>& a) {
        vector<int> v;
        while(a.size() > 1){
            v = {};
            for(int i = 0; i < a.size() - 1; i++){
                v.push_back((a[i] + a[i + 1]) % 10);
            }
            a = v;
        }
        
        return a[0];
    }
};