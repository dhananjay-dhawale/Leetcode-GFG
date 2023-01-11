class Solution {
    vector <int> cnt;
    vector <bool> app;
public:
    void dfs(int node, int par, vector <int> adj[]) {
        //cout << node << " " << par << "\n";
        for(auto &child : adj[node]) {
            if(child == par) {
                continue;
            }
            cnt[child] += app[child];
            dfs(child, node, adj);
            cnt[node] += cnt[child];
            //cout << node << " " << par << " " << child << " " << cnt[child] << " " << app[node] << "\n";
        }
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector <int> adj[n];
        for(auto &i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        cnt.resize(n);
        app = hasApple;
        dfs(0, -1, adj);
        for(int i = 0; i < n; i++) {
            adj[i].clear();
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += cnt[i] != 0;
        }
        return max(0, 2 * (ans - 1));
    }
};