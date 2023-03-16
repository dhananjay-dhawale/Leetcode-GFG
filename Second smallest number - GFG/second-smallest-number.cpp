//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
    string secondSmallest(int S, int D){
        if(D == 1) {
            return "-1";
        }
        vector <int> v(D);
        v[0] = 1;
        S -= 1;
        for(int i = D - 1; i > 0; i--) {
            if(S >= 9) {
                v[i] = 9;
                S -= 9;
            }
            else {
                v[i] = S;
                S = 0;
                break;
            }
        }
        if(S >= 8) {
            return "-1";
        }
        v[0] += S;
        S = 0;
        int i = D - 2;
        while(i >= 0 && v[i] == 9) {
            i -= 1;
        }
        v[i + 1] -= 1;
        v[i] += 1;
        string s = "";
        for(auto &i : v) {
            s += to_string(i);
        }
        return s;
    }   
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.secondSmallest(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends