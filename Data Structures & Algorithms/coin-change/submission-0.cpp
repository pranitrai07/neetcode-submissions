class Solution {
public:
    int coinChange(vector<int>& a, int amt) {
        vector<int> dp(amt+1, INT_MAX);
        dp[0] = 0;

        for (int i=1; i<=amt; i++){
            for (auto x: a){
                if (i >= x && dp[i-x] != INT_MAX) 
                    dp[i] = min(dp[i], 1 + dp[i-x]);
            }
        }
        return (dp[amt] == INT_MAX)? -1: dp[amt];
    }
};
