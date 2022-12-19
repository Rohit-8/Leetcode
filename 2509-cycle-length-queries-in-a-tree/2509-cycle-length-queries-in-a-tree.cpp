class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& q) {
        vector<int> ans;
        for(int i = 0; i < q.size(); i++){
            int a = q[i][0], b = q[i][1];
            int x = a, y = b;
            
            map<int, int> mp;
            int c = 1;
            while(a > 0){
                mp[a] = c;
                c ++;
                a = a / 2;
            }
            c = 0;
            while(b > 0){
                if(mp.count(b)){
                    ans.push_back(c + mp[b]);
                    break;
                }
                b = b / 2;
                c ++;
            }
        }
        
        return ans;
    }
};