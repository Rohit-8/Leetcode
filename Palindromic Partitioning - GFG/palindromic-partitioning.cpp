// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int dp[501][501];
    bool ispal(string &s,int i, int j){
        
        while(i<j){
            if(s[i]!=s[j])
                return false;
            
            i++, j--;
        }
            
        return true;
    }
    
    
    int res(string &s,int i, int j){
        if(i>=j) return 0;
        
        if(ispal(s,i,j)) return dp[i][j] = 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int temp = INT_MAX;
        for(int k = i; k<j; k++){
            int t = 1 + res(s,i,k)+ res(s,k+1,j);
            temp = min(t,temp);
        }
        
        return dp[i][j] = temp;
    }

    int palindromicPartition(string str)
    {
        // code here
        memset(dp, -1, sizeof(dp));
        
        return res(str,0,str.size()-1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends