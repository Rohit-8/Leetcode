class Solution {
public:
    bool lemonadeChange(vector<int>& a) {
        int f = 0, t = 0;
        for(int i = 0; i < a.size(); i++){
            if(a[i] == 5){
                f++; continue;
            }
            else if(a[i] == 10){
                if(f <= 0) return false;
                f--; t++;
            }
            else{
                if(f <= 0) return false;
                if(t){
                    t--;
                    f--; continue;
                }
                else if(f < 3) return false;
                else{
                    f -= 3;
                }
            }
        }
        
        return true;
    }
};