class Solution {
public:
    int compress(vector<char>& ch) {
        int n = ch.size();
        vector<char> ans;
        for(int i = 0; i < n; ){
            int c = 1;
            char st = ch[i];
            i++;
            while(i < n and ch[i] == st){
                c++; i++;
            }
            ans.push_back(st);
            if(c > 1){
                string t = to_string(c);
                for(int j = 0; j < t.size(); j++)
                    ans.push_back(t[j]);
            }
        }
        ch = ans;
        return ch.size();
    }
};