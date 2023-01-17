class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int zeroAfter = 0, oneBefore = 0, n = s.size(), res = INT_MAX;
        for(int i=0; i<n; i++) {
            if(s[i]=='0')
                zeroAfter++;
        }
        for(int i=0; i<n; i++) {
            if(s[i]=='0')
                zeroAfter--;
            res = min(res, zeroAfter+oneBefore);
            if(s[i]=='1')
                oneBefore++;
        }
        return res;
    }
};