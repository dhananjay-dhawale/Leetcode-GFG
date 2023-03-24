//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    string removeReverse(string S) {
        int n = S.size(), l = 0, r = n - 1;
        
        vector <int> f(26), good(n);
        
        for(auto &i : S) {
            f[i - 'a'] += 1;
        }
        
        int c = 0;
        
        while(l <= r) {
            while(l <= r && f[S[l] - 'a'] <= 1) {
                good[l] = 1;
                l += 1;
            }
            if(l < r && f[S[l] - 'a'] > 1) {
                f[S[l] - 'a'] -= 1;
                l += 1;
                c += 1;
            }
            
            while(l <= r && f[S[r] - 'a'] <= 1) {
                good[r] = 1;
                r -= 1;
            }
            if(l < r && f[S[r] - 'a'] > 1) {
                f[S[r] - 'a'] -= 1;
                r -= 1;
                c += 1;
            }
        }
        
        string s = "";
        
        for(int i = 0; i < n; i++) {
            if(good[i]) {
                s += S[i];
            }
        }
        
        if(c % 2) {
            reverse(s.begin(), s.end());
        }
        
        return s;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends