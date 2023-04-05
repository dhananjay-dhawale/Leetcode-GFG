//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSpecialNumbers(int N, vector<int> arr) {
        int mx = *max_element(arr.begin(), arr.end());
        vector <int> vis(mx + 1);
        sort(arr.begin(), arr.end());
        for(int i = 0; i < N - 1; i++) {
            if(arr[i] == arr[i + 1]) {
                vis[arr[i]] = 1;
            }
        }
        set <int> s(arr.begin(), arr.end());
        for(auto &i : s) {
            for(int j = i + i; j <= mx; j += i) {
                vis[j] = 1;
            }
        }
        int ans = 0;
        for(auto &i : arr) {
            ans += vis[i];
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends