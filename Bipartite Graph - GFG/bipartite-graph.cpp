//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> side(V, -1);
        bool is_bipartite = true;
        queue<int> q;
        for (int st = 0; st < V; ++st) {
            if (side[st] == -1) {
                q.push(st);
                side[st] = 0;
                while (!q.empty()) {
                    int v = q.front();
                    q.pop();
                    for (int u : adj[v]) {
                        if (side[u] == -1) {
                            side[u] = side[v] ^ 1;
                            q.push(u);
                        } else {
                            is_bipartite &= side[u] != side[v];
                        }
                    }
                }
            }
        }
        return is_bipartite;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends