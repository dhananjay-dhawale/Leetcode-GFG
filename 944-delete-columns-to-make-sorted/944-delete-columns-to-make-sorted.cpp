class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size();
        vector <vector <int>> v(m, vector <int> (n));
        cout << n << " " << m << "\n";
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                v[j][i] = strs[i][j];
            }
        }
        int c = 0;
        for(int i = 0; i < m; i++) {
            if(!is_sorted(v[i].begin(), v[i].end())) {
                c += 1;
            }
        }
        return c;
    }
};