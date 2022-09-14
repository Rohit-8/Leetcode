class Solution {
public:
    int numberOfSubarrays(vector<int>& a, int k) {
        int n = a.size();
        int ans = 0, c = 0;
        
        int left[n + 1];
        int right[n + 1];
        
        for(int i = 0; i < n; i++){
            if(a[i] % 2 == 0) c++;
            else{
                left[i] = c;
                c = 0;
            }
        }
        c = 0;
        for(int i = n - 1; i >= 0; i--){
            if(a[i] % 2 == 0) c++;
            else {
                right[i] = c;
                c = 0;
            }
        }
        c = 0;
        for(int i = 0, j = 0; i < n; i++){
            if(a[i] % 2 == 0) continue;
            c++;
            
            if(c == k){
                while(j <= i and a[j] % 2 != 1){
                    j++;
                }
                if(i == j)
                    ans += 1 + (left[i] + right[i] + left[i]* right[i]);
                
                else
                    ans += 1 + (left[j] + right[i] + left[j] * right[i]);
                
                j++;
                c--;
            }
        }
        
        return ans;
    }
};