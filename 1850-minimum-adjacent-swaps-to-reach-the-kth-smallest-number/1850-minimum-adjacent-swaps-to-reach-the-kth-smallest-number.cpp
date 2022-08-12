class Solution {
public:
    static bool cmp(char &a, char &b){
        return a-'0' < b-'0';
    }
    string solve(string &a) {
        for(int i = a.size()-1; i>0; i--){
            if(a[i]-'0' > a[i-1]-'0'){
                
                for(int j = a.size()-1; j>=i ; j--){
                    if(a[j]-'0'>a[i-1]-'0'){
                        swap(a[i-1], a[j]);
                        
                        sort(a.begin()+i,a.end(), cmp);
                        return a;
                    }
                }
            }
        }
        sort(a.begin(), a.end(), cmp);
        return a;
    }
    
    int getMinSwaps(string &a, int k) {
        string s = a;
        for(int i = 0; i < k; i++){
            solve(s);
        }
        
        int n = a.size();
        int ans = 0;
        for(int i = 0, j = 0; i < n; i++, j++){
            if(s[i] != a[j]){
                
                for(; j < n; j++){
                    
                    if(s[i] == a[j]){
                        ans += j - i;
                        break;
                    } 
                }
                for(; j > i; j--){
                    swap(a[j-1], a[j]);
                }
                j = i;
            }
        }
        
        return ans;
    }
};