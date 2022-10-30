class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        
        int n = a.size();
		int l = 0, r = n-1;
		while (l < r) {
			int mid = (l+r)/2;
			if ((mid%2 and a[mid]==a[mid-1]) or (mid%2 == 0 and a[mid] == a[mid+1]))
				l = mid + 1;
			
			else r = mid;
		}
		return a[l];
    }
};