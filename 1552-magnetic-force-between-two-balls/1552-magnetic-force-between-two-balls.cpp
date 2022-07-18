class Solution {
public:
    bool res(int val,vector<int>& a, int m){
        int prev = a[0];
        int c = 1;
        int mn = INT_MAX;
        for(int i = 1; i < a.size(); i++){
            if(a[i] - prev >= val){
                mn = min(mn, a[i]-prev);
                prev = a[i];
                c++;
            }
            
            if(c >= m) return true;
        }
        
        return c >= m;
    }
    
    int maxDistance(vector<int>& a, int m) {
        sort(a.begin(),a.end());
           
        int r = a[a.size()-1], l = 1;
        int ans = INT_MAX;
        
        while(l <= r){
            int mid = l + (r-l)/ 2;

            if(res(mid, a, m)){
                ans = mid;
                l = mid+1;
            }
            else
                r = mid-1;
        }
        return ans;
    }
};