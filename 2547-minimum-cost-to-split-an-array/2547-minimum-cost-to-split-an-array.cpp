class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        int n = nums.size();  
        vector<long long> dp(n, 1e13); 
        for(int i=0;i<n;++i){
            vector<int> occ(n+1); 
            long long cost = 0 ; 
            for(int j=i;j>-1;--j){
                occ[nums[j]]++; 
            	if(occ[nums[j]] == 2) cost+=2; 
                else if(occ[nums[j]]>2) cost++; 
                if(j) dp[i] = min(dp[i],dp[j-1]+cost+k); 
                else dp[i] = min(dp[i],cost+k); 
            }
        }
        return dp.back(); 
    }
};