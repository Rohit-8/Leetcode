#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
class Solution {
public:
    vector<int> countSmaller(vector<int>& a) {
        ordered_multiset p;
        vector<int> ans(a.size(), 0);
        for(int i =(int)a.size()-1;i>=0;i--){
            p.insert(a[i]);
            ans[i] = p.order_of_key(a[i]);
        }
        
        return ans;
        
    }
};