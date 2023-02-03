//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:	
	// calculate the maximum sum with out adjacent
	vector <int> dp;
	int f(int i, int *arr, int n) {
	    if(i >= n) {
	        return 0;
	    }
	    if(dp[i] != -1) {
	        return dp[i];
	    }
	    int a = arr[i] + f(i + 2, arr, n);
	    int b = f(i + 1, arr, n);
	    return dp[i] = max(a, b);
	}
	int findMaxSum(int *arr, int n) {
	    dp = vector <int> (n + 1, - 1);
	    return f(0, arr, n);
	}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends