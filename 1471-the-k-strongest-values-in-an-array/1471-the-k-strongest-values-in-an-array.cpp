class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        vector<int> ans;
        
        int j = 0;
        int c = 0;
        int mid = arr[(n-1)/2];
        for(int i = n-1; i >= j; ){
            c++;
            if(abs(arr[i] - mid) >= abs(arr[j] - mid)){
                ans.push_back(arr[i]); i--;
            }
            else ans.push_back(arr[j]), j++;
            if(c == k) break;
        }
        
        sort(ans.begin(), ans.end(), [](int &a, int &b){
            return a > b;
        });
        
        return ans;
    }
};