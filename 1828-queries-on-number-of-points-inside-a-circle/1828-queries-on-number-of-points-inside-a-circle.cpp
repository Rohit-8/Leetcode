class Solution {
public:
    
    bool dist(int x, int y, int p, int q, double r){
        x -= p, y -= q;
        double d = sqrt((double)(x * x) + (double) (y * y));
        
        return d <= r;
    }
    
    vector<int> countPoints(vector<vector<int>>& po, vector<vector<int>>& qe) {
        vector<int> ans;
        
        for(int i = 0; i < qe.size(); i++){
            int c = 0;
            double r = qe[i][2];
            int p = qe[i][0], q = qe[i][1];
            
            for(int j = 0; j < po.size(); j++){
                if(dist(po[j][0], po[j][1], p, q, r))
                    c++;
            }
            
            ans.push_back(c);
        }
        
        return ans;
    }
};