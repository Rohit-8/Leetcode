class MyQueue {
public:
    stack<int> s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        int sz1 = s1.size();
        while(sz1--){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        
        int sz2 = s2.size();
        while(sz2--){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int ans = s1.top();
        s1.pop();
        return ans;
        
    }
    
    int peek() {
      return  s1.top();
    }
    
    bool empty() {
       return s1.empty(); 
    }
};