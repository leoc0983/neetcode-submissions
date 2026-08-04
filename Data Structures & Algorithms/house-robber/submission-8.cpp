class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return rob_range(nums, nums.size()-1, memo);
    }
private:
    int rob_range(vector<int>& nums, int last, vector<int>& memo) {
        if(last < 0) {
            return 0;
        }
        if(memo[last] != -1) {
            return memo[last];
        }
        memo[last] = max((nums[last] + rob_range(nums, last-2, memo)), rob_range(nums, last-1, memo));
        return memo[last];
    }
};
