class Solution {
public:
    void reverse(vector<int> &a, int n){
        for(int i = 0; i <= n/2; i++){
            swap(a[i], a[n-i]);
        }
    }
    
    vector<int> pancakeSort(vector<int>& a) {
        priority_queue<int> pq;
        int n = a.size();
        
        for(int i = 0; i < n; i++)
            pq.push(a[i]);
        
        int j = n;
        vector<int> ans;
        while(!pq.empty()){
            
            int x = pq.top();
            pq.pop();
            j--;
            if(x == a[j]) continue;
            
            int i = j;
            while(i >= 0 and a[i] != x) i--;
            
            reverse(a, i);
            reverse(a, j);
            ans.push_back(i + 1);
            ans.push_back(j + 1);
        }
        
        return ans;
    }
};