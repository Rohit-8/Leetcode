class Solution {
public:
    pair<int, int> majorityElement(vector<int> &ar, int size){
        int ele, count = 0;
        for(int i = 0; i < size; i++){
            if(count == 0)
                ele = ar[i];
            if(ele == ar[i]){
                count++;
            }
            else
                count--;
        }
        count = 0;
        for(int i = 0; i < size; i++){
            if(ar[i] == ele){
                count++;
            }
        }
        if(count > size / 2)
            return {ele, count};
        
        return {-1, count};
    }
    
    long long minimumTotalCost(vector<int>& a, vector<int>& b) {
        int n = a.size();
        
        vector<int> v;
        long long ans = 0;
        for(int i = 0; i < n; i++){
            if(a[i] == b[i])
                v.push_back(a[i]), ans += i * 1ll;
        }
        // cout << " ans " << ans << endl;
        // for(int i = 0; i < v.size(); i++){
        //     cout << v[i] <<" ";
        // }
        // cout << endl;
        
        pair<int, int> t = majorityElement(v, (int)v.size());
        int el = t.first, c = t.second;
        if(el == -1){
            return ans;
        }
        c = c - (v.size() - c);
        
        // cout << " el " << el << endl;
        // cout << " c "<< c <<endl;
        
        for(int i = 0; i < n; i++){
            if(a[i] != el and b[i] != el and a[i] != b[i]){
                ans += i;
                c --;
            }
            if(c <= 0){
                return ans;
            }
        }
        
        return -1;
    }
};