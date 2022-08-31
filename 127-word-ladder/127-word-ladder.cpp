class Solution {
public:
    bool res(string &a, string &b){
        bool f = false;
        for(int i = 0; i < a.size(); i++){
            if(a[i] != b[i]){
                if(f) return false;
                f = true;
            }
        }
        return true;
    }
    
    int ladderLength(string bw, string ew, vector<string>& a) {
        
        queue<pair<string,int>> q;
        q.push({bw, 1});
        int n = a.size();
        map<string,int> m;
        
        while(!q.empty()){
            string s = q.front().first;
            int x = q.front().second;
            q.pop();
            
            if(s == ew) return x;
            for(int i = 0; i < n; i++){
                if(res(s, a[i]) and m[a[i]] <= 0){
                    q.push({a[i], x + 1});
                    m[a[i]] = 1;
                }
            }
        }
        
        return 0;
    }
};