class Solution {
public:
    int findKthLargest(vector<int>& a, int k) {
        priority_queue<int, vector<int> , greater<int>> p;
        
        for(int i = 0; i< a.size(); i++){
            p.push(a[i]);
            if(p.size()>k) p.pop();
        }
        return p.top();
    }
};