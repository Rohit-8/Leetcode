class Solution {
public:
    int longestOnes(vector<int>& a, int k) {
        int ans = 0;
        int c = 0, z = 0;
        for(int i = 0, j = 0; i < a.size(); i++){
            c++;
            if(a[i] != 1) z++;
            if(z > k){
                while(j <= i and z > k){
                    if(a[j] != 1) z--;
                    c--;
                    j++;
                }
            }
            ans = max(ans, c);
        }
        
        return ans;
    }
};