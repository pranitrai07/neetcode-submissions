class Solution {
public:
    int maxProduct(vector<int>& a) {
        int n = a.size(), ans = a[n-1];

        vector<int> mn(n), mx(n);
        mx[n-1] = a[n-1];
        mn[n-1] = a[n-1];

        for (int i=n-2; i>=0; i--){
            mx[i] = max(a[i], max(a[i] * mx[i+1], a[i] * mn[i+1]));
            mn[i] = min(a[i], min(a[i] * mx[i+1], a[i] * mn[i+1]));

            ans = max(ans, mx[i]);
        }

        return ans;
    }
};
