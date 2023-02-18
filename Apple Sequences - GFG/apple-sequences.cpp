//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int appleSequences(int n, int m, string s){
        int i = 0, j = 0, c1 = 0, c2 = 0, ans = 0;
        while(i < n) {
            c1 += s[i] == 'A';
            c2 += s[i] == 'O';
            while(j <= i && c2 > m) {
                c1 -= s[j] == 'A';
                c2 -= s[j] == 'O';
                j += 1;
            }
            i += 1;
            ans = max(ans, i - j);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M;
        cin >> N >> M;
        string arr;
        cin >> arr;
        
        Solution ob;
        cout << ob.appleSequences(N, M, arr) << endl;
    }
    return 0; 
} 
// } Driver Code Ends