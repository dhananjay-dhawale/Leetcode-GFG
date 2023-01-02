class Solution {
public:
    bool detectCapitalUse(string word) {
        int c = 0;
        for(auto &i : word) {
            if(isupper(i)) {
                c += 1;
            }
        }
        return c == word.size() || c == 0 || (c == 1 && isupper(word[0]));
    }
};