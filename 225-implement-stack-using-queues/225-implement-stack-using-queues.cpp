class MyStack {
public:
    queue <int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        int sz = q.size();
        q.push(x);
        while(sz--){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int tmp = q.front();
        q.pop();
        return tmp;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
    
};