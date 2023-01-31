//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minRepeats(string A, string B) {
        int n = A.size(), m = B.size();
        string s = "";
        for(int i = 0; i < m / n; i++) {
            s += A;
        }
        if(s.find(B) != string::npos) {
            return m / n;
        }
        s += A;
        if(s.find(B) != string::npos) {
            return m / n + 1;
        }
        s += A;
        if(s.find(B) != string::npos) {
            return m / n + 2;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends