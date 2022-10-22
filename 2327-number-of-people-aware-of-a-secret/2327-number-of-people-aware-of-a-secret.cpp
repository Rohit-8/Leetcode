#define ll long long
class Solution {
public:
    ll mod = 1000000007;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        priority_queue<pair<ll, ll>, vector<pair<ll,ll>> , greater<pair<ll,ll>>> pq;
        pq.push({1, 1});
        
        ll ans = 0;
        for(int i = 2; i <= n; i++){
            if(!pq.empty() and pq.top().first + forget == i){
                pq.pop();
            }
            if(pq.empty()) break;
            
            vector<pair<ll, ll>> v;
            ll c = 0;
            while(!pq.empty() and pq.top().first + delay <= i){
                v.push_back({pq.top().first, pq.top().second});
                c += pq.top().second % mod;
                pq.pop();
            }
            for(int j = 0; j < v.size(); j++){
                pq.push(v[j]);
            }
            pq.push({i, c});
        }
        while(!pq.empty()){
            ans += (pq.top().second % mod);
            pq.pop();
        }
        
        return ans % mod;
    }
};