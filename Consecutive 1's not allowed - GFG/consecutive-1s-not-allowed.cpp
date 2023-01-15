//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++

class Solution{
private:
    int n, mod = 1e9 + 7;    
    ll dp[2][100005];
public:
	// #define ll long long
	ll f(int prev, int i) {
	    if(i == n) {
	        return 1LL;
	    }
	    if(dp[prev][i] != -1) {
	        return dp[prev][i];
	    }
	    ll ans = 0;
	    if(prev == 0) {
	        ans += f(0, i + 1);
	        ans += f(1, i + 1);
	    }
	    else {
	        ans += f(0, i + 1);
	    }
	    return dp[prev][i] = ans % mod;
	}
	ll countStrings(int n) {
	    for(int i = 0; i < n; i++) {
	        dp[0][i] = -1;
	        dp[1][i] = -1;
	    }
	    this->n = n;
	    return (f(0, 1) + f(1, 1)) % mod;
	}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends