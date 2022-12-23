class Solution {
public:
    vector<long long> getDistances(vector<int>& a) {
        map<long long, pair<long long, long long>> mp;
        vector<long long> pre(a.size() + 1, 0);
        
        for(long long i = 0; i < a.size(); i++){
            if(mp.count(a[i]) == false){
                mp[a[i]] = {i, 0};
                pre[i] = 0;
            }
            else {
                long long ind = mp[a[i]].first;
                long long c = mp[a[i]].second;
                pre[i] = (i - ind) * (c + 1) + pre[ind]; 
                mp[a[i]] = {i, c + 1};
            }
        }
        
        map<long long, pair<long long, long long>> mp2;
        vector<long long> suff(a.size() + 1, 0);
        for(long long i = a.size() - 1; i >= 0; i --){
            if(mp2.count(a[i]) == false){
                mp2[a[i]] = {i, 0};
                suff[i] = 0;
            }
            else {
                // cout << i << " ";
                long long ind = mp2[a[i]].first;
                long long c = mp2[a[i]].second;
                suff[i] = (ind - i) * (c + 1) + suff[ind]; 
                // cout << ind << " " << c << endl;
                mp2[a[i]] = {i, c + 1};
            }
        }
        
        vector<long long> ans(a.size());
        for(int i = 0; i < a.size(); i++){
            ans[i] = pre[i] + suff[i];
        }
        
        // for(int i = 0; i < ans.size(); i++){
        //     cout << suff[i] << " ";
        // }
        
        return ans;
    }
};