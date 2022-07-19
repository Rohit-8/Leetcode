class Solution {
public:
    vector<int> findDuplicates(vector<int>& a) {
        
        vector<int>ans; 
        for(int i = 0; i < a.size(); i++){
          int x = abs(a[i])-1;
          a[x]*=-1;
            
          if(a[x]>0)
              ans.push_back(x+1);
        }
        return ans; 
    }
};