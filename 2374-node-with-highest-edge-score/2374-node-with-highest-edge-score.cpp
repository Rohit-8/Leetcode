class Solution {
public:
    int edgeScore(vector<int>& a) {
        long long mx = 0;
        int ans;
        map<long long, long long int> m;
        for(int i = 0; i < a.size(); i++){
            m[a[i]] += i;
        }
        for(auto x: m){
            if(mx < x.second){
                mx = x.second;
                ans = x.first;
            }
        }
        
        return ans;
    }
};