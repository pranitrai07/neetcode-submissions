class Solution {
public:
    int numDecodings(string& s) {
        int n = s.size();

        vector<int> dp(n+1);
        dp[n] = 1;
        if (s[n-1] != '0') dp[n-1] = 1;

        for (int i=n-2; i>=0; i--){
            if (s[i] == '0') continue;

            int num = stoi(s.substr(i, 2));
            dp[i] = dp[i+1];

            if (s[i+1] == '0'){
                if (num > 26) return 0;
                dp[i] = dp[i+2];
            } else {
                if (num <= 26) dp[i] += dp[i+2];
            }
        }

        return dp[0];
    }
};
