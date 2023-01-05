class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector <int> &a, const vector <int> &b){
            if(a[1] == b[1])
                return a[0] < b[0];
            return a[1] < b[1];
        });
        int c = 0, prev = points[0][1], n = points.size();
        for(int i=1; i<n; i++){
            if(points[i][0] > prev){
                c += 1;
                prev = points[i][1];
            }
        }
        return c+1;
    }
};