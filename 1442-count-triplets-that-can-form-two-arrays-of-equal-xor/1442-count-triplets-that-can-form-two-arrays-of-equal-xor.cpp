class Solution {
public:
    int countTriplets(vector<int>& a) {
        int n = a.size();
        
        int ans = 0;
        for(int i = 0; i < n - 1; i++){
            int x = 0;
            
            for(int j = i; j < n; j++){
                x ^= a[j];
                int y = 0;
                for(int k = j + 1; k < n; k++){
                    y ^= a[k];
                    if(y == x) ans++;
                }
            }
        }
        
        return ans;
    }
};