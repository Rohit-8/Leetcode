class Solution {
public:
    int maximumGroups(vector<int>& a) {
        int k = 1, n = a.size();
//         for(int i = 0; i < n; i += k){
//             if(n - i - 1 < k + 1) break;
//             k++;
//         }
        
//         return k;
        int ans = (-1 + sqrt(1 + 8 * n)) /  2;
        return ans;
    }
};