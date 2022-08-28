class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& a) {
        
        int n = a.size();
        int m = a[0].size();
        for(int i =0; i<m; i++ ){
            vector<int> v;
                int j=0;
                for(int k = i; k<m and j<n;k++){
                    v.push_back(a[j++][k]);
                }
            
            sort(v.begin(), v.end());
            int t = 0;
            // for(int j = 0; j<n; j++){
                j = 0;
                for(int k = i; k<m and j<n;k++){
                    a[j++][k] = v[t++];
                
            }
            
        }
        for(int i =1; i<n; i++ ){
            vector<int> v;
            int k = 0;
            for(int j = i; j<n and k<m; j++){
                // for(int k = 0; k<m;k++){
                    v.push_back(a[j][k++]);
                
            }
            sort(v.begin(), v.end());
            int t = 0;
            k = 0;
            for(int j = i; j<n and k<m; j++){
                // for(int k = 0; k<m;k++){
                    a[j][k++] = v[t++];
                }
            
            
        }
        
        return a;
    }
};