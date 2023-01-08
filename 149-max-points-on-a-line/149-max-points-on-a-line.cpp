class Solution {
public:
    int maxPoints(vector<vector<int>>& A) {
        //cout << fixed << setprecision(6);
        int result = 0, n = A.size();
    for(int i = 0; i < n; i++){
        int samePoint = 1;
        unordered_map<double, int> map;
        for(int j = i + 1; j < n; j++){
            if(A[i][0] == A[j][0]){
                map[INT_MAX]++;
            }
            else{
                double slope = double(A[i][1] - A[j][1]) / double(A[i][0] - A[j][0]);
                map[slope]++;
            }
        }
        int localMax = 0;
        for(auto it = map.begin(); it != map.end(); it++){
            localMax = max(localMax, it->second);
        }
        localMax += samePoint;
        result = max(result, localMax);
    }
    return result;
    }
};
