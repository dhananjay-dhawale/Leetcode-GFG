class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int s1 = 0, s2 = accumulate(nums.begin(), nums.end(), 0);
        int pref_sum = INT_MIN;
        int suff_sum = INT_MIN;
        int global_sum = nums[0], local_sum = 0, n = nums.size();
        
        for(int i=0; i<n; i++){
            s1 += nums[i];
            s2 -= nums[i];
            pref_sum  = max(pref_sum, s1);
            //suff_sum  = max(suff_sum, s2);
            local_sum = max(nums[i], nums[i]+local_sum);
            //cout << pref_sum << " " << suff_sum << " " << local_sum << "\n";
            global_sum = max({global_sum, local_sum, pref_sum+s2});
        }
        
        return global_sum;
    }
};

/*
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int local_sum = nums[0], global_sum = nums[0], n = nums.size(), s = 0;
        
        for(int i=1; i<n; i++){
            local_sum  = max(nums[i], nums[i]+local_sum);
            global_sum = max(global_sum, local_sum);
        }
        
        vector <int> pref(n+1), suff(n+1);
        
        s = nums[0];
        pref[0] = nums[0];
        for(int i=1; i<n; i++){
            s += nums[i];
            pref[i] = max(pref[i-1], s);
        }
        
        s = nums[n-1];
        suff[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            s += nums[i];
            suff[i] = max(suff[i+1], s);
        }
        
        for(int i=0; i<n-1; i++){
            //cout << pref[i] << " " << suff[i+1] << "\n";
            global_sum = max(global_sum, pref[i]+suff[i+1]);
        }
        
        return global_sum;
    }
};
*/