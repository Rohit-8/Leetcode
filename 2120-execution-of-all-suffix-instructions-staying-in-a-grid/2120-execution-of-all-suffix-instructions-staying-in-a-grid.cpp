class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& st, string s) {
        
        vector<int> ans;
        for(int i = 0; i < s.size(); i++){
            int x = st[0], y = st[1]; 
            int c = 0;
            for(int j = i; j < s.size(); j++){
                if(s[j] == 'L'){
                    if(y <= 0){
                        ans.push_back(c);
                        break;
                    }
                    c++; y --;
                }
                else if(s[j] == 'R'){
                    if(y >= n - 1){
                        ans.push_back(c);
                        break;
                    }
                    c++; y ++;
                }
                else if(s[j] == 'U'){
                    if(x <= 0){
                        ans.push_back(c);
                        break;
                    }
                    c ++;
                    x --;
                }
                else if(s[j] == 'D'){
                    if(x >= n - 1){
                        ans.push_back(c);
                        break;
                    }
                    c ++, x ++;
                }
            }
            // if(i == 1){
            //     cout << c << endl;
            //     cout << s.size() - i << endl;
            // }
            if(c == (s.size() - i))
                ans.push_back(c);
        }
        
        return ans;
    }
};