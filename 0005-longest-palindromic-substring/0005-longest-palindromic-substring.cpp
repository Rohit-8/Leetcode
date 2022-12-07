class Solution {
public:
    int check(string &s, int i, int j, deque<char> &t){
        int c = 0;
        for(; i >= 0 and j < s.size(); i--, j++){
            if(s[i] == s[j]){
                t.push_front(s[i]);
                t.push_back(s[j]);
                c += 2;
            }
            else return c;
        }
        return c;
    }
    string longestPalindrome(string s) {
        int x = 0;
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            deque<char> t;
            t.push_back(s[i]);
            int c = check(s, i - 1, i + 1, t) + 1;
            if(c > x){
                x = c;
                ans = "";
                for(int i = 0; i < t.size(); i++){
                    ans += t[i];
                }
            }
            if(i > 0 and s[i] == s[i - 1]){
                t.clear();
                t.push_back(s[i - 1]);
                t.push_back(s[i]);
                c = check(s, i - 2, i + 1, t) + 2;
                if(c > x){
                    x = c;
                    ans = "";
                    for(int i = 0; i < t.size(); i++){
                        ans += t[i];
                    }
                }
            }
        }
        // cout<< x <<endl;
        return ans;
    }
};