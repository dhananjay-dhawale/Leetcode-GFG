class Solution {
public:
    void dfs(int node, int par, vector <int> adj[], vector <vector <int>> &v, string &s) {
        for(auto &child : adj[node]) {
            if(child == par) {
                continue;
            }
            v[child][s[child] - 'a'] += 1;
            dfs(child, node, adj, v, s);
            for(int i = 0; i < 26; i++) {
                v[node][i] += v[child][i];
            }
        }
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector <vector <int>> v(n, vector <int> (26));
        vector <int> adj[n];
        for(auto &i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        dfs(0, -1, adj, v, labels);
        vector <int> ans(n);
        for(int i = 0; i < n ; i++) {
            ans[i] = v[i][labels[i] - 'a'];
        }
        ans[0] += 1;
        return ans;
    }
};