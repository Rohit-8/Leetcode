class Solution {
public:
    int longestOnes(vector<int>& a, int k) {
        int ans = 0;
        int c = 0, z = 0;
        for(int i = 0, j = 0; i < a.size(); i++){
            if(a[i] == 1) c++;
            else {
                c++;
                z++;
                if(z > k){
                    while(j <= i and z > k){
                        if(a[j] == 0) z--;
                        c--;
                        j++;
                    }
                }
            }
            ans = max(ans, c);
        }
        
        return ans;
    }
};