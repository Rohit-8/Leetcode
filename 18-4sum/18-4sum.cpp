class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int t) {
        vector<vector<int>> ans;
        
        if(a.size() < 4) return ans;
        sort(a.begin(), a.end());
        
        for(int i = 0; i < a.size(); i++){
            for(int j = i + 1; j < a.size(); j ++){
                
                int l = j + 1, r = a.size()-1;
                long long rem = t - a[i] - a[j]*1ll;
                for(; l < r;){
                    
                    int x = a[l] + a[r];
                    if(x == rem){
                        vector<int> v;
                        v.push_back(a[i]);
                        v.push_back(a[j]);
                        v.push_back(a[l]);
                        v.push_back(a[r]);
                        
                        ans.push_back(v);
                        
                        while(l < r and a[l] == v[2])
                            l ++;
                        while(l < r and a[r] == v[3])
                            r--;
                    }
                    else if(x > rem) r--;
                    else l ++;
                }
                
                while(j+1 < a.size() and a[j+1] == a[j]) j++;
                
            }
            
            while(i + 1 < a.size() and a[i+1] == a[i]) i++;
          
        }
        
        return ans;
    }
};