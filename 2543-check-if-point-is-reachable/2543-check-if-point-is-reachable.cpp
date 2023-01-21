class Solution {
public:
    bool isReachable(int x, int y) {
        while(x != y || x % 2 == 0 || y % 2 == 0) {
            while(x % 2 == 0) {
                x /= 2;
            }
            while(y % 2 == 0) {
                y /= 2;
            }
            if(x != y && x % 2 && y % 2) {
                if(x > y) {
                    x += y;
                }
                else {
                    y += x;
                }
            }
        }
        return x == 1 && y == 1;
    }
};