class Solution {
public:
    int totalFruit(vector<int>& a) {
        int nums1 = a[0], nums2 = -1;
        int l = 0, k = 0;
        
        int ans = 0, i;
        int cons1 = 0, cons2 = 0;
        for(i = 1; i < a.size(); i++){
            if(a[i] == nums1){
                cons1++;
                cons2 = 0;
                continue;
            }
            else if (nums2 == -1 or a[i] == nums2){
                nums2 = a[i];
                cons2++, cons1 = 0;
                continue;
            }
            ans = max(ans, i - k);
            if(a[i - 1] == nums1){
                l = cons1;

            }
            else l = cons2, nums1 = a[i - 1];
            nums2 = a[i];
            cons2 = 1;
            cons1 = 0;
            k = i - l;
            if(i == 4) cout << k << endl;
        }
        ans = max(ans, i - k);
        return ans;
    }
};