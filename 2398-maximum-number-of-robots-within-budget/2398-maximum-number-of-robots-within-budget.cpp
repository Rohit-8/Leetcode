class Solution {
public:
    int maximumRobots(vector<int>& a, vector<int>& b, long long budget) {
        
        int n = b.size();
        long long int pre[n] , sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += b[i];
            pre[i] = sum;
        }
        sum = 0;
        map<long long int , long long int> mp;
        long long int temp = 0 , ans = 0 , cnt = 0 , mx = 0 ;
        priority_queue<long long int> pq;
        int j = 0;
        for(int i = 0; i < n ; i++)
        {
            // temp +=
            sum += b[i];
            
            mx = max(mx ,(long long int)a[i]);
            
            mp[a[i]]++;
            long long int k = i - j + 1;
            temp = k * sum + mx;
            if(temp <= budget)
            {
                // cnt++;
                ans = max(ans , k);
            }
            else
            {
                // cnt++;
                while(temp > budget)
                {
                    if(j > i)
                    {
                        sum = 0;
                        temp = 0;
                        mp.clear();
                        cnt = 0;
                        // j++;
                        break;
                    }
                    sum -= b[j];
                    mp[a[j]]--;
                    
                    if(mp[mx] == 0)
                    {
                        mp.erase(mx);
                    }
                    if(mp[a[j]] == 0)
                        mp.erase(a[j]);
                    if(mp.size() == 0)
                    {
                        mx = 0;
                        // sum
                    }
                    else
                    {
                        // mx = *(mp.rbegin() -> first);
                        auto it = mp.rbegin() -> first;
                        mx = it;
                    }
                    j++;
                    cnt--;
                   
                    temp = sum *(i - j + 1) + mx;
                }
                ans = max(ans ,(long long int)i - j + 1);
            }
            // ans = max(ans , cnt);
            
        }
        return ans;
    }
};