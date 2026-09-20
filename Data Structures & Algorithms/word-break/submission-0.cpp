class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int> mp;
        for (auto x: wordDict) mp[x]++;

        int n = s.size();
        vector<bool> dp(n+1);
        dp[n] = true;

        for (int i=n-1; i>=0; i--){
            string p;
            for (int j=i; j<n; j++){
                p += s[j];
                int sz = p.size();

                if (mp[p]) dp[i] = dp[i+sz];

                if (dp[i]) break;
            }
        }

        return dp[0];
    }
};
