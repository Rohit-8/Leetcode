class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    map<int , int> m;
    SmallestInfiniteSet() {
        for(int i = 1; i <= 1000; i++){
            pq.push(i);
            m[i]++;
        }
    }
    
    int popSmallest() {
        int x = pq.top();
        m[x]--;
        pq.pop();
        return x;
    }
    
    void addBack(int num) {
        if(m[num] > 0)
            return;
        m[num] = 1;
        pq.push(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */