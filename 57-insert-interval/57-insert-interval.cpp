class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& b) {
        int n = a.size();
        vector <vector<int>> v;
        int i = 0;
        while(i < n && a[i][1] < b[0]) {
            v.push_back(a[i++]);
        }
        if(i < n) {
            int x = min(a[i][0], b[0]);
            int y = b[1];
            //cout << x << " " << y << " " << i << "\n";
            while(i < n && a[i][0] <= b[1]) {
                i += 1;
            }
            if(i - 1 >= 0) {
                y = max(y, a[i - 1][1]);
            }
            v.push_back({x, y});
        }
        else {
            v.push_back(b);
        }
        while(i < n) {
            v.push_back(a[i++]);
        }
        return v;
    }
};

/*
[[1,3],[6,9]]
[1,3]
[[1,3],[6,9]]
[2,5]
[[1,3],[6,9]]
[0,2]
[[1,3],[6,9]]
[1,1]
[[1,3],[6,9]]
[0,0]
[[1,3],[6,9]]
[1,3]
[[1,3],[6,9]]
[7,8]
[[1,3],[6,9]]
[10,11]
[[1,3],[6,9]]
[2,10]
[[1,3],[6,9]]
[0,10]
[[1,3],[6,9]]
[4,5]
*/
