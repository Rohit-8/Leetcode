class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        int a = 0, b = 0, c = 0;
        int n = s.size();
        for(int i = 0, j = 0; i < n; i++){
            if(s[i] == 'a') a++;
            else if(s[i] == 'b') b++;
            else if(s[i] == 'c') c++;
            
            while(j <= i and a > 0 and b > 0 and c > 0){
                ans += (n - i);
                if(s[j] == 'a') a--;
                else if(s[j] == 'b') b--;
                else if(s[j] == 'c') c--;
                j++;
            }
        }
        
        return ans;
    }
};