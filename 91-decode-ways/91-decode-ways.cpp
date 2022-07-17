class Solution {
public:
    
    vector<long long> dp;
    long long res(string &s, int i){
        if(i < 0) return 1;
        
        if(dp[i] != -1) return dp[i];
        
        long long sum = 0;
        if(s[i] != '0'){
            sum += res(s, i-1);
            if(i > 0){
                
                int x = s[i]-'0' + 10 * (s[i-1]-'0');
                if(x > 9 and x < 27)
                    sum += res(s, i-2);
            }
        }
        else {
            if(i == 0) return dp[i] = INT_MAX;
            int x = s[i]-'0' + 10 * (s[i-1]-'0');
            if(x > 9 and x < 27)
                sum += res(s, i-2);
            else return dp[i] = INT_MAX;
        }
        
        return dp[i] = sum;
    }
    
    int numDecodings(string s) {
        
        dp.resize(s.size() +1, -1);
        long long x = res(s, s.size()-1);
        if(x >= INT_MAX) return 0;
        
        return (int)x;
    }
};