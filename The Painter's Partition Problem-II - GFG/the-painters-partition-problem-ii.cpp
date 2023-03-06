//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long minTime(int arr[], int n, int k) {
        long  l = 1, r = accumulate(arr, arr + n, 0L);
        auto f = [&] (int m) {
            int c = 0, s = 0, i = 0;
            while(i < n) {
                if(arr[i] > m) {
                    return false;
                }
                if(arr[i] + s > m) {
                    c += 1;
                    s = arr[i];
                }
                else {
                    s += arr[i];
                }
                i += 1;
            }
            c += s > 0;
            return c <= k;
        };
        while(l < r) {
            int m = (l + r) / 2;
            if(f(m)) {
                r = m;
            }
            else {
                l = m + 1;
            }
        }
        return l;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends