class Solution {
public:
    int minDeletions(string s) {
        
        unordered_map<char,int> m;
        for(int i = 0; i< s.size(); i++)
            m[s[i]]++;
        
        vector<int> v;
        for(auto x: m){
            v.push_back(x.second);
        }
        
        sort(v.begin(), v.end());
        int ans = 0;
        for(int i = v.size() - 2; i>=0; i--){
            
            if(v[i+1] == 1){
                ans+= v[i];
                v[i] = 1;
            }
            else if(v[i] >= v[i+1]){
                ans +=(v[i]-v[i+1]+1);
                v[i] = max(v[i+1]-1,0); 
            }      
        }
        
        return ans;
    }
};