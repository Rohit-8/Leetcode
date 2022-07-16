class Solution {
public:
    vector<int> majorityElement(vector<int>& a) {
        
        int n = a.size();
        int num1 = -1, num2 = -1, c1 = 0, c2 = 0;
        
        for(int i = 0; i < n; i++){
            if(num1 == a[i]) c1 ++;
            else if(num2 == a[i]) c2++;
            else if(c1 == 0){
                num1 = a[i];
                c1 ++;
            }
            else if(c2 == 0) num2 = a[i], c2 ++;
            else c1--, c2--;
        }
        c1 = c2 = 0;
        for(int i = 0;i < n; i++){
            if(a[i] == num1) c1 ++;
            else if(a[i] == num2) c2++;
        }
        if(c1 > n/3 and c2 > n/3)
            return {num1, num2};
        if(c1 > n/3) return {num1};
        if(c2 > n/3) return {num2};
        
        return {};
    }
};