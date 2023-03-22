//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    long long solve(int X,int Y,string S){
        int n = S.size(), i = 0;
        long long s  = 0;
        stack <char> st;
        
        auto f1 = [&] () {
            //cout << S << " " << s << "\n";
            n = S.size();
            while(i < n) {
                if(!st.empty() && st.top() == 'p' && S[i] == 'r') {
                    st.pop();
                    s += X;
                }
                else {
                    st.push(S[i]);
                }
                i += 1;
            }
        };
        
        auto f2 = [&] () {
            //cout << S << " " << s << "\n";
            n = S.size();
            while(i < n) {
                if(!st.empty() && st.top() == 'r' && S[i] == 'p') {
                    st.pop();
                    s += Y;
                }
                else {
                    st.push(S[i]);
                }
                i += 1;
            }
        };
        
        if(X > Y) {
            f1();
            S = "";
            while(!st.empty()) {
                S += st.top();
                st.pop();
            }
            reverse(S.begin(), S.end());
            i = 0;
            f2();
        }
        else {
            f2();
            S = "";
            while(!st.empty()) {
                S += st.top();
                st.pop();
            }
            reverse(S.begin(), S.end());
            i = 0;
            f1();
        }
        
        return s;
    }
};


//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends