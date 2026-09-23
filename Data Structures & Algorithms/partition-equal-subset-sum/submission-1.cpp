class Solution {
public:
    int rec(vector<int>& a, int i, int sm){
        if (!sm) return true;

        if (i >= a.size()) return false;

        bool ans = false;
        // take
        if (sm >= a[i]) ans = rec(a, i+1, sm-a[i]);

        if (ans) return true;

        // not take
        ans = rec(a, i+1, sm);

        return ans;
    }

    bool canPartition(vector<int>& a) {
        int s=0;
        for (auto x: a) s += x;

        if (s%2) return false;

        int req = s/2;
        return rec(a, 0, req);
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
