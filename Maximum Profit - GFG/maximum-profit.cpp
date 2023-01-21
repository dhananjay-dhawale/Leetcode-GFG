//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
private:
    int N, dp[402][505][2], ans = 0;
public:
    int dfs(int k ,int idx, int prices[], bool state) {
        //cout << k << " " << sum << " " << idx << " " << state << "\n";
        if(k%2 == 0){
            ans = max(ans, dp[k][idx][state]);
        }
        if(k == 0 || idx == N)
            return 0;
        if(dp[k][idx][state] != -1)
            return dp[k][idx][state];
        int op1 = 0, op2 = 0;
        if(state == 0){
            op1 = dfs(k-1, idx + 1, prices, !state) - prices[idx];
            op2 = dfs(k, idx + 1, prices, state);
        }
        else{
            op1 = dfs(k-1, idx + 1, prices, !state) + prices[idx];
            op2 = dfs(k, idx + 1, prices, state);
        }
        //cout << k << " " << idx << " " << state << " " << op1 << " " << op2 << "\n";
        dp[k][idx][state] = max(op1, op2);
        if(k%2 == 0){
            ans = max(ans, dp[k][idx][state]);
        }
        return dp[k][idx][state];
    }
    int maxProfit(int K, int N, int prices[]) {
        memset(dp, -1, sizeof(dp));
        this->N = N;
        dfs(2*K, 0, prices, 0);
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends