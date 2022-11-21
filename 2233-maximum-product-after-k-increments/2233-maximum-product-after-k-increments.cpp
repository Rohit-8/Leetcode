class Solution {
public:
    int maximumProduct(vector<int>& a, int k) {
        long long ans = 1;
        long long mod = 1000000007;
        if(a.size() == 1)
            return a[0] + k;
        
        sort(a.begin(), a.end());
        long long j = -1, add = 0;
        for(long long i = 1; i < a.size(); i ++){
            long long x = a[i] - a[i - 1];
            x *= i*1ll;
            if(k >= x){
                j = i;
                k -= x;
                a[i - 1];
            }
            else{
                j = i - 1;
                break;
            }
        }
        cout<<j<<" "<<add<<endl;
        add = k / (j + 1);
        k -= (add * (j + 1));
        for(int i = 0; i <= j; i++){
            a[i] = a[j] + add + (k >= 1);
            k --;
        }
        for(int i = 0; i < a.size(); i++){
            ans = (ans * a[i]) % mod;
        }
        
        return ans;
    }
};