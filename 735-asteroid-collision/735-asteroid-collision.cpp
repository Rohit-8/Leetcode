class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> st;
        vector<int> ans;
        
        for(int i = 0; i < a.size(); i++){
            if(a[i] > 0){
                st.push(a[i]); continue;
            } 
            while(!st.empty() and st.top() > 0 and abs(st.top()) < abs(a[i])) st.pop();
            
            if(st.empty() or st.top() < 0){
                st.push(a[i]); continue;
            }
            if(st.top() == abs(a[i])) st.pop();
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};