class Solution {
public:
    int numSubarraysWithSum(vector<int>& a, int k) {
        int n = a.size();
        if(k == 0){
            int ans = 0, c = 0;
            for(int i = 0; i < n; i ++){
                if(a[i] == 1) {
                    ans += (c * (c + 1) / 2);
                    c = 0;
                }
                else c ++;
            }
            ans += (c * (c + 1) / 2);
            return ans;
        }
        
        int left[n + 1];
        int right[n + 1];
        int c = 0;
        for(int i = 0; i < n; i++){
            if(a[i] == 0) c++;
            else{
                left[i] = c;
                c = 0;
            }
        }
        c = 0;
        for(int i = n - 1; i >= 0; i--){
            if(a[i] == 0) c++;
            else {
                right[i] = c;
                c = 0;
            }
        }
        c = 0;
        int ans = 0;
        for(int i = 0, j = 0; i < n; i++){
            if(a[i] == 0) continue;
            c++;
            
            if(c == k){
                while(j <= i and a[j] != 1){
                    j++;
                }
                if(i == j){
                    ans += 1 + (left[i] + right[i] + left[i]* right[i]);
                    cout<<left[i]<<" "<< right[i]<<" ";
                }
                else{
                    ans += 1 + (left[j] + right[i] + left[j] * right[i]);
                    cout<<left[i]<<" "<< right[i]<<" ";
                }
                j++;
                c--;
            }
        }
        for(int i = 0; i < n; i++){
            if(a[i] == 1){
                // cout<<right[i]<<" ";
            }
        }
        
        return ans;
    }
};