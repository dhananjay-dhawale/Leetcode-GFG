//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

const int N = 4e4;
bool seive[N];
int spf[N];
std::vector<int> primes;

void preprocess(){
    spf[1] = 1;
    for(int i = 2; i < N; ++i){
        seive[i] = true;
        spf[i] = i;
    }
 
    for(int i = 2; i < N; ++i){
        if (seive[i]) {
            primes.push_back(i);
            for(long long j = i * 1LL * i; j < N; j += i){
                seive[j] = false;
                spf[j] = i;
            }
        }
    }
}

class Solution{   
  public:
    int shortestPath(int a, int b)
    {   
        preprocess();
        int ans = 0;
        queue <int> q;
        q.push(a);
        vector <int> vis(100000);
        vis[a] = 1;
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                int t = q.front();
                q.pop();
                if(t == b) {
                    return ans;
                }
                int wt = 1;
                for(int i = 0; i < 4; i++) {
                    wt *= 10;
                    for(int j = 0; j <= 9; j++) {
                        if(i == 0 && j == 0) {
                            continue;
                        }
                        int c = (t / wt) * wt + j * (wt / 10) + (t % (wt / 10));
                        int cnt = 0, num = c;
                        while(num) {
                            cnt += 1;
                            num /= 10;
                        }
                        if(!vis[c] && seive[c] && cnt == 4) {
                            vis[c] = 1;
                            q.push(c);
                        }
                    }
                }
            }
            ans += 1;
        }
        return -1;
    }
};


//{ Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    Solution obj;
    while(t--)
    {
        int Num1,Num2;
        cin>>Num1>>Num2;
        int answer=obj.shortestPath(Num1,Num2);
        cout<<answer<<endl;
    }
}
// } Driver Code Ends