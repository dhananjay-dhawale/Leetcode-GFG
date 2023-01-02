//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int removeStudents(int H[], int N) {
        vector <int> v;
        for(int i = 0; i < N; i++){
            auto it = lower_bound(v.begin(), v.end(), H[i]);
            if(it == v.end())
                v.push_back(H[i]);
            else
                *it = H[i];
        }
        return N - v.size();
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}
// } Driver Code Ends