//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        int hash1[26]={0}, hash2[26]={0};
        for(int i=0; i<n; i++){
            if(islower(str[i]))
                hash1[str[i]-'a']++;
            else
                hash2[str[i]-'A']++;
        }
        int j=0, k=0;
        string output="";
        for(int i=0; i<n; i++){
            if(islower(str[i])){
                while(hash1[j]==0)
                    j++;
                output+=(char)('a'+j);
                //cout<<j<<" j "<<hash1[j]<<" "<<output<<"\n";
                hash1[j]--;
            }
            else{
                while(hash2[k]==0)
                    k++;
                output+=(char)('A'+k);
                //cout<<k<<" k "<<hash2[k]<<" "<<output<<"\n";
                hash2[k]--;
            }
        }
        return output;
    }
};


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends