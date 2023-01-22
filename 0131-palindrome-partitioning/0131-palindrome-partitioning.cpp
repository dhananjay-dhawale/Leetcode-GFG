class Solution {
private:
    int n, dp[16][16];
    vector <vector<string>> ans;
    string s;
public:
    void dfs(int i, vector <string> &v){
        if(i == n){
            ans.push_back(v);
            return;
        }
        int j = i;
        string t = "";
        while(j < n){
            t += s[j];
            if(dp[i][j]){
                v.push_back(t);
                dfs(j+1, v);
                v.pop_back();
            }
            j += 1;
        }
    }
    vector<vector<string>> partition(string s) {
        this->s = s;
        n = s.size();
        vector <string> v;
        memset(dp, 0, sizeof(dp));
        dp[n-1][n-1] = 1;
        for(int i=0; i<n-1; i++){
            dp[i][i] = 1;
            int l = i-1, r = i+1;
            while(l >= 0 && r < n && s[l] == s[r]){
                dp[l][r] = 1;
                l -= 1;
                r += 1;
            }
            l = i;
            r = i+1;
            while(l >= 0 && r < n && s[l] == s[r]){
                dp[l][r] = 1;
                l -= 1;
                r += 1;
            }
        }
        dfs(0, v);
        return ans;
    }
};