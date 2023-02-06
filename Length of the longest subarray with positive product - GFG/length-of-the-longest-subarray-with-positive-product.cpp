//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
        // Function to return the length of the
        //longest subarray with ppositive product
        int maxLength(vector<int> &arr,int n){
            int i = 0, ans = 0;
            while(i < n) {
                int pos = 0, neg = 0, j = i;
                while(i < n && arr[i]) {
                    pos += arr[i] > 0;
                    neg += arr[i] < 0;
                    i += 1;
                }
                if(pos || neg) {
                    int len = pos + neg;
                    if(neg % 2) {
                        int k = j, c = 0;
                        while(k < n && arr[k] > 0) {
                            c += 1;
                            k += 1;
                        }
                        c += 1;
                        ans = max(ans, len - c);
                        c = 0;
                        k = i - 1;
                        while(k >= 0 && arr[k] > 0) {
                            c += 1;
                            k -= 1;
                        }
                        c += 1;
                        ans = max(ans, len - c);
                    }
                    else {
                        ans = max(ans, len);
                    }
                }
                i += 1;
           }
           return ans;
        }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}
// } Driver Code Ends