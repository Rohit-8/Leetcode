class Solution {
public:
    int form(string &s, map<char, int> &mp, vector<int> &sc){
        int x = 0;
        for(int i = 0; i < s.size(); i++){
            if(mp[s[i]] <= 0)
                return 0;
            mp[s[i]] --;
            x += (sc[s[i] - 'a']);
        }
        return x;
    }
    
    int res(vector<string> &w, int n, map<char, int> mp, vector<int> &sc, vector<int> &dp){
        if(n >= w.size()) return dp[n] = 0;
        
        // if(dp[n] != -1) return dp[n];
        
        int sum = res(w, n + 1, mp, sc, dp);
        int x = form(w[n], mp, sc);
        if(x){
            // cout << x << endl;
            // cout << w[n] << endl;
            sum = max(sum, x + res(w, n + 1, mp, sc, dp));
        }
        
        return dp[n] = sum;
    }
    
    int maxScoreWords(vector<string>& w, vector<char>& l, vector<int>& sc){
        map<char, int> mp;
        for(int i = 0; i < l.size(); i++){
            mp[l[i]]++;
        }
        vector<int> dp(w.size() + 1, -1);
        return res(w, 0, mp, sc, dp);
    }
};