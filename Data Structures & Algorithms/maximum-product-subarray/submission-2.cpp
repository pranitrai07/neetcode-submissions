class Solution {
public:
    int maxProduct(vector<int>& a) {
        int n = a.size(), ans = a[n-1], curMin = a[n-1], curMax = a[n-1];

        for (int i=n-2; i>=0; i--){
            int mx = max(a[i], max(a[i] * curMax, a[i] * curMin));
            int mn = min(a[i], min(a[i] * curMax, a[i] * curMin));

            curMax = mx;
            curMin = mn;

            ans = max(ans, curMax);
        }

        return ans;
    }
};
