class Solution {
public:
    long long countGood(vector<int>& a, int k) {
        int n = a.size();
        long long ans = 0, sum = 0, j = 0;
        map <int, int> mp;
        for(int i = 0; i < n; i++) {
            mp[a[i]] += 1;
            sum += mp[a[i]] - 1;
            while(j < i && sum - (mp[a[j]] - 1) >= k) {
                sum -= (mp[a[j]] - 1);
                mp[a[j]] -= 1;
                j += 1;
            }
            if(sum >= k) {
                ans += j + 1;
            }
        }
        return ans;
    }
};