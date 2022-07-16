class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        int n = a.size();
        unordered_map<int,int> m;
        for(int i = 0;i < n; i++)
            m[a[i]]++;
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(m.find(a[i]-1) == m.end()){
                int c = 1;
                int x = a[i];
                while(m.find(++x) != m.end()) c++;
                ans = max(ans, c);
            }
        }
        
        return ans;
    }
};