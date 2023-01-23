//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


struct SCC {
    int n;
    std::vector<std::vector<int>> adj, radj, comp;
    std::vector<int> order, who;
    std::vector<bool> used;
    int cc = 0;

    SCC(){ }
    SCC(int _n): n(_n), adj(_n), comp(_n), radj(_n) {}

    void dfs_top(int v) {
        used[v] = true;
        for (auto nxt : adj[v]) 
            if (!used[nxt])
                dfs_top(nxt);

        order.push_back(v);
    }
    void dfs_comp(int v) {
        used[v] = 1;
        comp[cc].push_back(v); 
        who[v] = cc;

        for (auto nxt : radj[v])
            if (!used[nxt]) 
                dfs_comp(nxt);
    }
    std::vector<std::pair<int, int>> ed;
    void add(int a, int b){
        adj[a].push_back(b), radj[b].push_back(a);
        ed.push_back({a, b});
    }
    void build() {
        who.assign(n, -1); used.assign(n, 0);
        for (int i = 0; i < n; i++) {
            if (!used[i])
                dfs_top(i);
        }
        std::fill(used.begin(), used.end(), false);
        for (int i = 0; i < n; i++){
            int v = order[n-1-i];
            if (!used[v]) {
                dfs_comp(v);
                cc++;
            }
        }
    }
} g;

class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        SCC g(V);
        for(int i = 0; i < V; i++) {
            for(auto &j : adj[i]) {
                g.add(i, j);
            }
        }
        g.build();
        return g.cc;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends