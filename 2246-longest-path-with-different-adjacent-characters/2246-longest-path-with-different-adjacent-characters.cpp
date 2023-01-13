class Solution {
private:
    int ans ;
    string s;    
public:
    void dfs(int node, vector <vector<int>> &cnt, vector <int> adj[]) {
        int mx1 = 0, mx2 = 0;
        for(auto &child : adj[node]) {
            cnt[s[child] - 'a'][child] += 1;
            dfs(child, cnt, adj);
            if(s[node] != s[child]) {
                int c = cnt[s[child] - 'a'][child];
                if(c >= mx1) {
                    mx2 = mx1;
                    mx1 = c;
                }
                else if(c >= mx2) {
                    mx2 = c;
                }
            }
        }
        cnt[s[node] - 'a'][node] = 1 + mx1;
        ans = max(ans, 1 + mx1 + mx2);
    }
    int longestPath(vector<int>& parent, string s) {
        this->s = s;
        int n = s.size();
        vector <int> adj[n];
        for(int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }
        vector <vector<int>> cnt(26, vector <int> (n, 0));
        ans = 0;
        dfs(0, cnt, adj);
        return ans;
    }
};