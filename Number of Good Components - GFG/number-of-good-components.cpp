//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int u, vector <int> &vis, vector <vector <int>> &G, vector <int> &vec) {
        for(auto &v : G[u]) {
            if(vis[v]) {
                continue;
            }
            vis[v] = 1;
            vec.push_back(v);
            dfs(v, vis, G, vec);
        }
    }
    int findNumberOfGoodComponent(int V, vector<vector<int>>& G) {
        int ans = 0;
        vector <int> vis(V + 1);
        for(int i = 1; i <= V; i++) {
            if(!vis[i]) {
                int c = 0;
                vis[i] = 1;
                vector <int> v;
                v.push_back(i);
                dfs(i, vis, G, v);
                for(auto &j : v) {
                    c += G[j].size();
                }
                int m = v.size();
                ans += ((m * (m - 1) / 2) == c / 2);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends