#define ll long long
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

class Solution {
public:
    int reversePairs(vector<int>& arr) {
        tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update> st;
        st.insert({0ll + arr[0], 0ll});
        ll ans = 0;
        int n = arr.size();
        
        for(int i = 1; i < n; i++){
            
            int smaller = st.order_of_key({2ll * arr[i], i});
            ans += ((ll)st.size() - smaller);
            st.insert({0ll + arr[i], 0ll + i});
        }
        return ans;
    }
};