class MinStack {
public:
    stack<long long> st;
    long long mn;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            mn = val; return;
        }
        if(mn <= val){
            st.push(val);
            return;
        }
        st.push(2ll * val - mn);
        mn = val;
    }
    
    void pop() {
        if(st.top() < mn){
            mn = 2 * mn - st.top();
            st.pop();
            return;
        }
        st.pop();
    }
    
    int top() {
        if(st.top() < mn){
            return mn;
        }
        return st.top();
    }
    
    int getMin() {
        return mn;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */