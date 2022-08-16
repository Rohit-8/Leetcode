class Solution {
public:
    int maximumXOR(vector<int>& a) {
        int n = a.size(), mn = 0;
        
        for(int i = 31; i >= 0; i--){
            for(int j = 0; j < n; j++){
                if(a[j] & (1<<i)){
                    mn = mn | (1<<i); break;
                }
            }
        }
        
        return mn;
    }
};