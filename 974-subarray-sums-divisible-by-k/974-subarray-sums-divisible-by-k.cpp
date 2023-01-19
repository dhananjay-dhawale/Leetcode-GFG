class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0, sum = 0;
        map <int, int> mp;
        mp[0] = 1;
        for(auto &i : nums) {
            sum += i;
            ans += mp[((sum % k) + k ) % k]++;
        }
        return ans;
    }
};