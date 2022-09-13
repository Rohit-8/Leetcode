class Solution {
public:
    int characterReplacement(string a, int k) {
        int ans = 0;
        
        for(char ch = 'A'; ch <= 'Z'; ch++){
            int c = 0, z = 0;
            for(int i = 0, j = 0; i < a.size(); i++){
                c++;
                if(a[i] != ch) z++;
                if(z > k){
                    while(j <= i and z > k){
                        if(a[j] != ch) z--;
                        c--;
                        j++;
                    }
                }

                ans = max(ans, c);
            }
        }
        
        return ans;
    }
};