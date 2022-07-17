class Solution {
public:
    
    int res(int n, set<int> &st, int j){
        
        int sum = 0;
        if(j <= n) sum ++; 
        
        if(j >= n) return sum;
        
        for(int i = 0; i < 10; i++){
            int x = st.size();
            st.insert(i);
            
            if(x < st.size()){
                sum += res(n, st, j + 1);
                st.erase(i);
            }
        }
        return sum;
    }
    
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        set<int> st;
        
        int ans = 1;
        for(int i = 1; i < 10; i++){
            st.insert(i);
            ans += res(n, st, 1);
            st.erase(i);
        }
        
        return ans;
    }
};