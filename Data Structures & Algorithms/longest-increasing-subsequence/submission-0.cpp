class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n = a.size(), ans=0;
        vector<int> dp(n, 1);

        for (int i=n-1; i>=0; i--){
            int mx = 0;
            for (int j=i+1; j<n; j++){
                if (a[j] > a[i]) mx = max(mx, dp[j]);
            }
            dp[i] += mx;
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};

// 7 8 9 10 1 2 3 4 5 6 