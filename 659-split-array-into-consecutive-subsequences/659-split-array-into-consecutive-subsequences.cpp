class Solution {
public:
    bool isPossible(vector<int>& a) {
        unordered_map<int, int> m;
        for(int i = 0; i < a.size(); i++)
            m[a[i]]++;

        for(int i = 0;i < a.size(); i++){
            int val = a[i];
            if(m[val]==0)
                continue;

            int f = m[val], c = 0;
            while(m[val] and f <= m[val]){
                f = max(f, m[val]);
                m[val]--;
                val++;
                c++;
            }
            if(c < 3) return false;
        }
        return true;
    }
};