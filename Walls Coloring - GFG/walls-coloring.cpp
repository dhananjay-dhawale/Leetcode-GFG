//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minCost(vector<vector<int>> &C, int N) {
        int a = C[0][0], b = C[0][1], c = C[0][2];
        for(int i = 1; i < N; i++) {
            int d = C[i][0] + min(b, c);
            int e = C[i][1] + min(a, c);
            int f = C[i][2] + min(a, b);
            a = d;
            b = e;
            c = f;
        }
        return min({a, b, c});
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends