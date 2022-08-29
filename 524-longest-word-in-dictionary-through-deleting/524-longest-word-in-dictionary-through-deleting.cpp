class Solution {
public:
    
    string findLongestWord(string s, vector<string>& a) {
        string ans = "";
        int mx = 0;
        for(int i = 0; i < a.size(); i++){
            int k = 0;
            int x = a[i].size();
            for(int j = 0; j < s.size() and k < x; j++){
                if(s[j] == a[i][k]) k++;
            }
            if(k >= x){
                if(x > mx){
                    mx = x; 
                    ans = a[i];
                }
                if(x == mx){
                    for(int j = 0; j < x; j++){
                        if(a[i][j] < ans[j]){
                            ans = a[i]; break;
                        }
                        else if(ans[j] < a[i][j]) break;
                    }
                }
            }
        }
        
        return ans;
    }
};