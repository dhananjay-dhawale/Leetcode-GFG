class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector <int> left_mx(n), right_mx(n);
        
        stack <int> s;
        for(int i = 0; i < n; i++) {
            while(!s.empty() && nums[s.top()] >= nums[i]) {
                s.pop();
            }
            if(s.empty()) {
                left_mx[i] = 0;
            }
            else {
                left_mx[i] = s.top() + 1;
            }
            s.push(i);
        }
        
        while(!s.empty()) {
            s.pop();
        }
        
        for(int i = n - 1; i >= 0; i--) {
            while(!s.empty() && nums[s.top()] >= nums[i]) {
                s.pop();
            }
            if(s.empty()) {
                right_mx[i] = n - 1;
            }
            else {
                right_mx[i] = s.top() - 1;
            }
            s.push(i);
        }
        
        int ans = 0;
        for(int idx = 0; idx < n; idx++) {
            int i  = left_mx[idx];
            int j  = right_mx[idx];
            int mn = nums[idx];
            if(i <= k && k <= j) {
                ans = max(ans, mn * (j - i + 1));
            }
        }
        cout << "\n";
        return ans;
    }
};