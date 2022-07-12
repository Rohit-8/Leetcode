class Solution {
public:
    bool solve(vector<int>& m, int idx, vector<int> &s){
          if(idx == m.size()){
               if(s[0] == 0 && s[1] == 0 && s[2] == 0 && s[3] == 0) return true;
               return false;
          }
        
          for(int i =0; i<4; i++){
              if(m[idx] > s[i]) continue;
              s[i] -= m[idx];
              
              if(solve(m, idx + 1, s)) return true;
              s[i] += m[idx];
          }
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
         int sum = accumulate(matchsticks.begin(), matchsticks.end(),0);
        
         if(sum % 4 != 0) return false;
         int side = sum / 4;
        
         sort(matchsticks.rbegin(), matchsticks.rend());
        
         vector<int> sides(4,side);
         return solve(matchsticks, 0, sides);
    }
};