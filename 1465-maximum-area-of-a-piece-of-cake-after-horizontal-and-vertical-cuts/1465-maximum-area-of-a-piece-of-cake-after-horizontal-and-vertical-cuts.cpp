class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());
        
        long long mxh = 0, mxc = 0;
        for(int i = 1; i < hc.size(); i++){
            mxh = max(mxh, 1ll*hc[i]-hc[i-1]);
        }
        mxh = max(mxh, 1ll*h - hc[hc.size()-1]);
        mxh = max(mxh, 1ll*hc[0]); 
        
        for(int i = 1; i < vc.size(); i++){
            mxc = max(mxc, 1ll*vc[i]-vc[i-1]);
        }
        mxc = max(mxc, 1ll*w-vc[vc.size()-1]);
        mxc = max(mxc, 1ll*vc[0]);
        
        return (mxc*mxh)%1000000007;
    }
};