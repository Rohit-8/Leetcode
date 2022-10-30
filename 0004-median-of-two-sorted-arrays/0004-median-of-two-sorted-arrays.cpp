class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        
        if(a.size() > b.size()) return findMedianSortedArrays(b, a);

        int n = a.size();
        int m = b.size();
                
        int l = 0, r = n;
           
        while(l <= r){

            int cut1 = (r+l)>>1;
            int cut2 = (n+m+1) / 2 - cut1;
            
            int left1 = cut1 == 0 ? INT_MIN : a[cut1 - 1];
            int left2 = cut2 == 0 ? INT_MIN : b[cut2 - 1];

            int right1 = cut1 == n ? INT_MAX : a[cut1];
            int right2 = cut2 == m ? INT_MAX : b[cut2];
            
            if(left1 <= right2 and left2 <= right1){
                if((n+m) % 2 == 0) 
                    return (max(left1, left2) + min(right1,right2))/2.0;
                
                return max(left1,left2); 
            }
            else if(left1 > right2) r = cut1 - 1;
            else l = cut1 + 1;
        }
        
        return 0.0;
    }
};