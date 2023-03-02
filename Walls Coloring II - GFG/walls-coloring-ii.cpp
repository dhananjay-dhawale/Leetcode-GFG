//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minCost(vector<vector<int>> &C) {
        int n = C.size(), k = C[0].size();
        
        auto f = [&](int i) -> std::tuple<int, int, int, int> {
            int mn1 = 1e9, mn2 = 1e9, i1 = -1, i2 = -1;
            for(int j = 0; j < k; j++) {
                if(C[i][j] < mn1) {
                    i2 = i1;
                    mn2 = mn1;
                    i1 = j;
                    mn1 = C[i][j];
                }
                else if(C[i][j] < mn2) {
                    i2 = j;
                    mn2 = C[i][j];
                }
            }
            return tie(mn1, i1, mn2, i2);
        };
        
        if(k == 1) {
            return n == 1 ? C[0][0] : -1;
        }
        
        for(int i = 1; i < n; i++) {
            auto result = f(i - 1);
            int mn1 = get<0>(result);
            int i1  = get<1>(result);
            int mn2 = get<2>(result);
            int i2  = get<3>(result);
            for(int j = 0; j < k; j++) {
                C[i][j] += j == i1 ? mn2 : mn1;
            }
        }
        
        return *min_element(C[n - 1].begin(), C[n - 1].end());
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> costs(n, vector<int>(k));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) cin >> costs[i][j];
        }
        Solution obj;
        cout << obj.minCost(costs) << endl;
    }
}
// } Driver Code Ends