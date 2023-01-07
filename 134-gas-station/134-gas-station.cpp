class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int a = 0, b = 0, i = 0, j = 0, n = gas.size();
        while(i < n){
            if(i == j){
                if(a && b)
                    return i;
                a += cost[j];
                b += gas[j];
                j += 1;
            }
            j %= n;
            while(i != j && a <= b){
                a += cost[j];
                b += gas[j];
                j += 1;
                j %= n;
            }
            while(i < n && a > b){
                a -= cost[i];
                b -= gas[i];
                i += 1;
            }
        }
        return -1;
    }
};