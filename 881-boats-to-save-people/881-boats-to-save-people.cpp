class Solution {
public:
    int numRescueBoats(vector<int>& a, int lm) {
        
        int j = a.size() - 1;
        int n = a.size(), ans = 0;
        sort(begin(a), end(a));
        
        for(int i = 0; i <= j; ){
            if(i == j){
                ans ++;
                break;
            }
            if(a[j] + a[i] <= lm) ans++, j--, i++;
            else ans ++, j--;
        }
        
        return ans;
    }
};