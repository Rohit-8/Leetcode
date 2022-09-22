class Solution {
public:
    bool res(vector<int> &a, int k, int h){
        int x = 0;
        for(int i = 0; i < a.size(); i++){
            x += a[i]/k;
            if(a[i] % k) x++;
            if(x > h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& a, int h) {
        long long ans = 0, l = 1, r = 1e18;
        while(l <= r){
            long long mid = l + (r - l) / 2;
            if(res(a, mid, h)){
                ans = mid; r = mid - 1;
            }
            else l = mid + 1;
        }
        
        return ans;
    }
};