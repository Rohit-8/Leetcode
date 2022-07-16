class Solution {
public:
    void merge(vector<int>& a1, int n, vector<int>& a2, int m) {
        
        for(int i = 0, j = n; i < m; i++, j++){
            a1[j] = a2[i];
        }
        
        int gap = (n + m)/2 + (n+m)%2;
        
        while(gap > 0){
            int i = 0, j = gap;
            while(j < n + m){
                if(a1[i] > a1[j])
                    swap(a1[i], a1[j]);
                i++, j++;
            }
            if(gap == 1) break;
            gap = gap/2 + gap%2;
        }
    }
};