//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int carpetBox(int A, int B, int C, int D){
        int ans = A + B;
        
        int x = A, y = B, c = 0;
        while(x > C) {
            x /= 2;
            c += 1;
        }
        while(y > D) {
            y /= 2;
            c += 1;
        }
        
        ans = min(ans, c);
        
        x = A, y = B, c = 0;
        while(x > D) {
            x /= 2;
            c += 1;
        }
        while(y > C) {
            y /= 2;
            c += 1;
        }
        
        ans = min(ans, c);
        
        return ans;
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends