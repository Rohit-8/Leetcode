class Solution {
public:
    int rev(int n){
        int sum = 0;
        for(int i = n; i > 0; i /= 10){
            sum = sum * 10 + (i % 10);
        }
        return sum;
    }
    
    int countDistinctIntegers(vector<int>& a) {
        unordered_set<int> st;
        int n = a.size();
        for(int i = 0; i < n; i++){
            st.insert(a[i]);
            st.insert(rev(a[i]));
        }
        return st.size();
    }
};