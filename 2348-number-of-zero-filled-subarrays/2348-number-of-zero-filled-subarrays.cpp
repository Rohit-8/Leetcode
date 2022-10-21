class Solution {
public:
    long long zeroFilledSubarray(vector<int>& a) {
        long long ans = 0;
        for(int i = 0; i < a.size(); i++){
            if(a[i] == 0){
                int j = i + 1;
                while(j < a.size() and a[j] == 0)
                    j++;
                
                ans += (((j - i) *1ll * (j - i + 1)) / 2);
                i = j;
            }
        }
        
        return ans;
    }
};