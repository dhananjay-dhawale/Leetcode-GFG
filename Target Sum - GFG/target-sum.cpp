//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
    int n;
    vector <int> A;
  public:
    int f(int i, bool k, int s) {
        if(i == n) {
            return s == 0;
        }
        int ans = 0;
        if(k) {
            ans += f(i + 1, k, s - A[i]);
            ans += f(i + 1, !k, s - A[i]);
        }
        else {
            ans += f(i + 1, k, s + A[i]);
            ans += f(i + 1, !k, s + A[i]);
        }
        return ans;
    }
    int findTargetSumWays(vector<int>&A ,int T) {
        n = A.size();
        this->A = A;
        return (f(0, 0, T) + f(0, 1, T)) / 2;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends