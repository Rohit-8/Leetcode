class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        for(int i = n - 1; i >= 0; i--){
            digits[i]++;
            if(digits[i] == 10){
                if(i == 0){
                    digits.push_back(0);
                    digits[i] = 1;
                }
                else digits[i] = 0;
            }
            else break;
            // 9 8 9 9
        }
        
        return digits;
    }
};