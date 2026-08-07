class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        vector<int> memo(len+1, -1);
        cost.push_back(0);
        return minCostCS_dp(cost, len, memo);
    }
private:
    int minCostCS_dp(vector<int>& cost, int last, vector<int>& memo) {
        if(memo[last] != -1) {
            return memo[last];
        }
        if(last < 0) {
            return 0;
        }
        if(last == 0 || last == 1) {
            return cost[last];
        }
        memo[last] = cost[last] + min(minCostCS_dp(cost, last-1, memo), minCostCS_dp(cost, last-2, memo));
        return memo[last];
    }
};
