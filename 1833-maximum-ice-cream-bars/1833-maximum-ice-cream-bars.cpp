class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int c = 0, i = 0, n = costs.size();
        sort(costs.begin(), costs.end());
        while(i < n) {
            if(c + costs[i] > coins) {
                break;
            }
            c += costs[i];
            i += 1;
        }
        return i;
    }
};