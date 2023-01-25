//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int minOperation(string s) {
        int i = 0, ans = 0, n = s.size();
        int len = 1, sz = 1;
        while(i + 2 * len <= n) {
            //cout << len << " " << s.substr(i, len) << " " << s.substr(i + len, len) << "\n";
            if(s.substr(i, len) == s.substr(i + len, len)) {
                sz = len + 1;
            }
            len += 1;
        }
        ans += sz;
        i += max(1, 2 * sz - 2);
        return ans + n - i;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends