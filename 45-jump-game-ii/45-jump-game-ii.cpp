class Solution {
public:
    int jump(vector<int>& a) {
        int jmp = 0, n = a.size() - 1, curEnd = 0, curfar = 0;
        for(int i = 0; i < n; i++){
            curfar = max(curfar, i + a[i]);
            if(curfar >= n) return jmp + 1;
            if(i == curEnd){
                jmp++;
                curEnd = curfar;
            }
        }
        return jmp;
    }
};