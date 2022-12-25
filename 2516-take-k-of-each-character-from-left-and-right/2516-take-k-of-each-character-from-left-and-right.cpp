class Solution {
public:
    void res(char &ch, int &a, int &b, int &c){
        if(ch == 'a') a++;
        else if(ch == 'b') b++;
        else c++;
    }
    int takeCharacters(string s, int k) {
        if(k == 0) return 0;
        int a , b, c;
        a = b = c = 0;
        int n = s.size();
        for(int i = 0; i < n; i++){
            res(s[i], a, b, c);
        }
        
        // cout << a << " " << b << " " << c << endl;
        
        if(a < k or b < k or c < k)
            return -1;
        
        int ans = n, cn = 0;
        for(int i = 0, j = 0; i < n and j < n; i++){
            /////// a /////////////////
            if(s[i] == 'a'){
                if(a > k){
                    a --, cn ++;
                    // continue;
                }
                else{
                    ans = min(ans, n - cn);
                    while(j < i and s[j] != s[i]){
                        res(s[j], a, b, c);
                        cn --;
                        j ++;
                    }
                    j ++;
                }
            }
            ///////////// b /////////
            else if(s[i] == 'b'){
                if(b > k){
                    b --, cn ++;
                    // continue;
                }
                else{
                    ans = min(ans, n - cn);
                    while(j <= i and s[j] != s[i]){
                        res(s[j], a, b, c);
                        cn --;
                        j ++;
                    }
                    j ++;
                }
            }
            ///////// c ///////////
            else if(s[i] == 'c'){
                if(c > k){
                    c --, cn ++;
                    // continue;
                }
                else{
                    ans = min(ans, n - cn);
                    while(j <= i and s[j] != s[i]){
                        res(s[j], a, b, c);
                        cn --;
                        j ++;
                    }
                    j ++;
                }
            }
            ans = min(ans, n - cn);
            
        }
        
        return ans;
    }
};