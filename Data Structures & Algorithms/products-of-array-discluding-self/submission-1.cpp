class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a) {
        int n = a.size();
        vector<int> l(n, 1), r(n, 1);

        l[0] = a[0];
        r.back() = a.back();

        for (int i=1; i<n; i++) {
            l[i] = l[i-1] * a[i];
            r[n-i-1] = r[n-i] * a[n-i-1];
        }

        vector<int> ans(n, 1);
        for (int i=0; i<n; i++){
            if (i-1>=0) ans[i] *= l[i-1];
            if (i+1<n) ans[i] *= r[i+1];
        }

        return ans;
    }
};
