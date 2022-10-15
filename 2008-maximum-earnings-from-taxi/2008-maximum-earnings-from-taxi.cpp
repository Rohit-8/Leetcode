class Solution {
public:
	long long maxTaxiEarnings(int n,vector<vector<int>>& r) {
		int m=r.size();
		sort(r.begin(),r.end());
		vector<int> st;
		for(int i=0;i<m;i++) st.push_back(r[i][0]);
		vector<long long> dp(m+1,0);
		for(int i=m-1;i>=0;i--){
			int ind=lower_bound(st.begin(),st.end(),r[i][1])-st.begin();
			long long pick=(r[i][1]-r[i][0]+r[i][2])+dp[ind];
			long long notpick=dp[i+1];
			dp[i]=max(pick,notpick);
		}
		return dp[0];
	}
};