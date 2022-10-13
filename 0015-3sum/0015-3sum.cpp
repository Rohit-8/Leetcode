class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        sort(a.begin(), a.end());
        
        vector<vector<int>> ans;
        set<vector<int>> st;
        for(int i = 0; i < a.size()-1; i++){
            int sum = a[i];
            
            int j = i + 1, k = a.size()-1;
            while(j < k){
                if(sum + a[j] + a[k] == 0){
                    st.insert({a[i], a[j], a[k]});
                    j++;
                }
                else if(sum + a[j] + a[k] > 0) k--;
                else j++;
            }
            if(i + 1 < a.size() and a[i] == a[i+1]){
                while(i +1 < a.size() and a[i] == a[i+1]) i++;
                i--;
            }
            
        }
        if(st.size() > 0){
            for(auto x: st)
                ans.push_back(x);
        }
        
        return ans;
    }
};