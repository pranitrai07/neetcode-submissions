class Solution {
public:
    int helper(vector<int> a){
        int n = a.size();
        if (n == 1) return a[0];

        a[n-2] = max(a[n-2], a[n-1]);

        for (int i=n-3; i>=0; i--) a[i] = max(a[i+1], a[i] + a[i+2]);

        return a[0];
    }

    int rob(vector<int>& a) {
        int n = a.size();

        if (n == 1) return a[0];
        if (n == 2) return max(a[0], a[1]);

        int l = a.back();
        a.pop_back();

        int ans = helper(a);

        a.push_back(l);
        a.erase(a.begin());

        ans = max(ans, helper(a));

        return ans;
    }
};
