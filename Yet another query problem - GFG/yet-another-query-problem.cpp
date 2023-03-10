//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> solveQueries(int N, int num, vector<int> &A, vector<vector<int>> &Q) {
        int n = Q.size(), m = A.size();
        map <int, int> mp;
        vector <int> freq(m);
        for(int i = 0; i < m; i++) {
            mp[A[i]] += 1;
        }
        for(int i = 0; i < m; i++) {
            freq[i] = mp[A[i]];
            mp[A[i]] -= 1;
        }
        vector <vector <int>> pref(m, vector <int> (m + 1));
        pref[0][freq[0]] += 1;
        for(int i = 1; i < m; i++) {
            pref[i][freq[i]] += 1;
            for(int j = 0; j <= m; j++) {
                pref[i][j] += pref[i - 1][j];
            }
        }
        vector <int> ans(n);
        for(int i = 0; i < n; i++) {
            int l = Q[i][0];
            int r = Q[i][1];
            int k = Q[i][2];
            ans[i] = pref[r][k] - (l == 0 ? 0 : pref[l - 1][k]);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int num;
        cin>>num;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        vector<vector<int>> Q(num, vector<int>(3));
        for(int i=0;i<num;i++){
            for(int j=0;j<3;j++){
                cin>>Q[i][j];
            }
        }
        Solution obj;
        vector<int> res = obj.solveQueries(N, num, A, Q);
        
        for(auto ele:res){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends