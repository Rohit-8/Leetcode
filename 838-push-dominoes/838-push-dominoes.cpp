class Solution {
public:
    string pushDominoes(string s) {
        int n = s.size();
        
        for(int i = 0, j = -1; i < n; i++){
            if(i > 0 and s[i] == 'L' and s[i-1] == 'L' and j != -1)
                continue;
            
            if(s[i] == 'L'){
                j = i - 1;
                while(j >= 0 and s[j] == '.'){
                    s[j] = 'L'; j--;
                }
                j = i;
                cout<<" dgfd ";
            }
            
            else if(s[i] == 'R'){
                bool f = false;
                j = i + 1;
                
                while(j < n and s[j] != 'L'){
                    if(s[j] == 'R'){
                        f = true; break;
                    }
                    j++;
                }
                
                if(j >= n or f){
                    while(i < n and i < j) s[i] = 'R', i++;
                    i = j - 1;
                    continue;
                }
                int x = j - i - 1;
                
                x /= 2;
                int y = x;
                int k = i + 1;
                while(y--) s[k] = 'R', k++;
                y = x;
                k = j-1;
                while(y--) s[k] = 'L', k--;
                i = j;
            }
            
        }
        
        return s;
    }
};