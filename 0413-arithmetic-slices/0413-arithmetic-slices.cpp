class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        int n = a.size();
        
        int ans = 0;
        for(int i = 0; i < n - 2; i++){
            int diff = a[i + 1] - a[i];
            int c = 2;
            bool f = false;
            for(int j = i + 2; j < n; j++){
                if(a[j] - a[j - 1] == diff) ans++;
                else{
                    break;
                }
            }
        }
        
        return ans;
    }
};