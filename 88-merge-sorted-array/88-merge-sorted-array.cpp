class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        if(n == 0) return;
        
        int j = n-1, k = m-1;
        int i ;
        for(i = n+m-1;k>=0 and j>=0;){
            if(j>=0 and a[k]>=b[j])
                a[i--] = a[k--];
            else if(j>=0 and a[k]<b[j])a[i--] = b[j--];
        }
        while(j>=0){
            a[i--] = b[j--];
        }
        
    }
};