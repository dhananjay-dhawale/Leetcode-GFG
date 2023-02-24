//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkCompressed(string S, string T) {
        int i=0,j=0,n=S.length(),m=T.length();
        while(i<n && j < m ){
            if(S[i] >='A' && S[i] <='Z' && T[j] >='A' && T[j] <='Z' && S[i] != T[j] ){
                return 0;
            }
            else if(T[j] >='0'&& T[j] <='9'){
                string str;
                while(T[j] >='0' && T[j] <='9')str+=T[j++];
                if(i+ stoi(str)-1 >= n)return 0;
                i += stoi(str)-1;
                j--;
            }
            i++; j++;
        }
        return 1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends