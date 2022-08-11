class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> m;
        int n = s.size();
        
        for(int i = 0; i < n; i++)
            m[s[i]]++;
        
        int j = 0;
        int x = 0;
        vector<int> ans;
        for(int i = 0; i < n; i++){
            x++;
            m[s[i]]--;
            if(m[s[i]] <= 0){
                while(j < n and m[s[j]] <= 0) j++;
            }
            
            if(j > i) ans.push_back(x), x = 0;
        }
        
        return ans;
    }
};