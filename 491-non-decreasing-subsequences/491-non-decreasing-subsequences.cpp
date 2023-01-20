class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector <vector<int>> ans;
        int n = nums.size();
        int k = 1<<n;
        for(int i = 0; i<k; i++){
            vector <int> v;
            int num = i, j;
            for(j=n-1; j>=0; j--){
                if(num&1){
                    if(v.empty())
                        v.push_back(nums[j]);
                    else if(v.back() >= nums[j])
                        v.push_back(nums[j]);
                    else
                        break;
                }
                num >>= 1;
            }
            reverse(v.begin(), v.end());
            if(j == -1 && v.size()>1)
                ans.push_back(v);
        }
        sort(ans.begin(), ans.end());
        auto ip = std::unique(ans.begin(), ans.end());
        ans.resize(std::distance(ans.begin(), ip));
        return ans;
    }
};