//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int noConseBits(int n) {
        int j = (1 << 30), c = 0;
        while(j) {
            if(n & j) {
                c += 1;
                if(c == 3) {
                    n ^= j;
                    c = 0;
                }
            }
            else {
                c = 0;
            }
            j >>= 1;
        }
        return n;
    }
};


//{ Driver Code Starts.

int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        int ans = sol.noConseBits(n);
        cout << ans << '\n';
    }

    return 0;
}

// } Driver Code Ends