class Solution {
public:
    string convert(string s, int n) {
        int t = s.size();
        vector<vector<char>> ch(n, vector<char> (t , '0'));
        int k = 0;
        int x = max(1, n - 1);
        int h = x;
        int j = 0;
        for(int i = 0; i < t; ){
            if(i % x == 0)
            {
                for(j = 0; j < n; j++){
                    if(k >= s.size()) {
                        cout<<i<<" ks "<<endl; break;
                    }
                    ch[j][i] = s[k++];
                }
                j = 0; i++;
            }
            else
            {
                while(i % x and i < t){
                    j = (j + h - 1 + n) % n; 
            
                    if(i % x == 0 or i >= t){
                        break;
                    }
                    ch[j++][i++] = s[k++];
                    if(k >= s.size()) {
                        cout<<i<<endl; break;
                    }
                }
                
            }
            
            if(k >= s.size()) {
                cout<<i<<"khatam "<<endl; break;
            }
        }
        
        cout<<endl;
        s = "";
        // string ans;
        for(int i = 0; i < n; i++){
            for(j = 0; j < t; j++){
                if(ch[i][j] != '0')
                    s.push_back(ch[i][j]);
                
                // cout<<ch[i][j]<<" ";
            }
            // cout<<endl;
        }
        
        return s;
    }
};