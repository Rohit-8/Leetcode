// class Solution {
// public:
//     int minimizeArrayValue(vector<int>& a) {
//         long sum = a.size() - 1;
//         int mx = 0;
//         int k = 1;
//         for(int i = a.size() - 2; i >= 0; i--){
//             sum += a[i];
//             k ++;
//             mx = max(mx, (int)(sum / k + (sum % k ? 1 : 0)));
//         }
        
//         return mx = max(a[0], mx);
//     }
// };

class Solution {
public:
    int minimizeArrayValue(vector<int>& a) {
        
        long sum = a[0];
        int mx = a[0];
        for(int i = 1; i < a.size(); i++){
            sum += a[i];
            mx = max(mx, (int)((sum/ (i + 1)) + ((sum % (i + 1))? 1: 0)));
        }
        
        return mx;
    }
};