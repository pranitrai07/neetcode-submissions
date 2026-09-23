class Solution {
public:
    int rec(vector<int>& a, int i, int sm, vector<vector<bool>>& dp){
        if (!sm) return true;

        if (i >= a.size()) return false;

        if (dp[i][sm]) return true;

        // take
        if (sm >= a[i]) dp[i][sm] = rec(a, i+1, sm-a[i], dp);

        if (dp[i][sm]) return true;

        // not take
        dp[i][sm] = rec(a, i+1, sm, dp);

        return dp[i][sm];
    }

    bool canPartition(vector<int>& a) {
        int s=0, n = a.size();
        for (auto x: a) s += x;

        if (s%2) return false;

        int req = s/2;
        vector<vector<bool>> dp(n, vector<bool>(s+1, false));
        return rec(a, 0, req, dp);
        // vector<int> dp(req+1);
        // dp[0] = 1;
        
        // for (int p=1; p<=req; p++){
        //     for (auto x: a){
        //         if (p >= x && dp[p-x]) {
        //             dp[p] = 1;
        //             break;
        //         }
        //     }
        //     cout << dp[p] << endl;
        // }

        // return (dp[req]>0);
    }
};
