class Solution {
public:
    int numDecodings(string& s) {
        if (s[0] == '0') return 0;

        int n = s.size();
        if (n==1) return 1;

        vector<int> dp(n+1);
        dp[n] = 1;
        if (s[n-1] != '0') dp[n-1] = 1;

        for (int i=n-2; i>=0; i--){
            if (s[i] == '0') {
                if (s[i+1] == '0') return 0;
                continue;
            }

            int num = stoi(s.substr(i, 2));

            if (s[i+1] == '0'){
                if (num > 26) return 0;
                dp[i] = dp[i+2];
            } else {
                dp[i] = dp[i+1];
                if (num <= 26) dp[i] += dp[i+2];
            }
        }

        return dp[0];
    }
};
