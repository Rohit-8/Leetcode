class StockSpanner {
public:
    stack<int> st;
    int x = 0;
    vector<int> v;
    StockSpanner() {
        
    }
    
    int next(int p) {
        v.push_back(p);
        while(!st.empty() and v[st.top()] <= p)
            st.pop();
        
        int ans ;
        if(st.empty()) ans = x + 1;
        else ans = x - st.top();
        st.push(x);
        x++;
        
        return ans;
    }
};
/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */