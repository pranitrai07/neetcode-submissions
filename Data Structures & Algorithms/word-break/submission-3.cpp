class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for (auto& x: wordDict) st.insert(x);

        int n = s.size();
        vector<bool> dp(n+1);
        dp[n] = true;

        for (int i=n-1; i>=0; i--){
            string p;
            for (int j=i; j<n; j++){
                p += s[j];
                int sz = p.size();

                if (st.find(p) != st.end()) dp[i] = dp[i+sz];

                if (dp[i]) break;
            }
        }

        return dp[0];
    }
};
