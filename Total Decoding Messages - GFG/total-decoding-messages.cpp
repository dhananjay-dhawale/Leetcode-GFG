//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int CountWays(string s){
		    int mod = 1e9 + 7, n = s.size(), dp[n + 2] = {0};
		    dp[0] = 1;
		    dp[1] = 1;
		    for(int i = 2; i <= n; i++) {
		        if(s[i - 1] != '0') 
		            dp[i] = dp[i - 1];
		        if((s[i - 2] == '1') || (s[i - 2] == '2' && s[i - 1] <= '6'))
		            dp[i] = (dp[i] + dp[i - 2]) % mod;
		    }
		    return dp[n];
		}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends