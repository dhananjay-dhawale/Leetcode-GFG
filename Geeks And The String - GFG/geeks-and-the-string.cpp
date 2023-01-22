//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        stack <char> st;
        for(auto &i : s) {
            st.push(i);
            while(st.size() >= 2) {
                char c1 = st.top(); st.pop();
                char c2 = st.top(); st.pop();
                if(c1 != c2) {
                    st.push(c2);
                    st.push(c1);
                    break;
                }
            }
        }
        string t = "";
        while(!st.empty()) {
            t += st.top();
            st.pop();
        }
        reverse(t.begin(), t.end());
        return t.empty() ? "-1" : t;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends