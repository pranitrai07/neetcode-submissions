class Solution {
public:
    int rob(vector<int>& a) {
        int n = a.size();
        if (n==1) return a[0];
        a[n-2] = max(a[n-1], a[n-2]);

        for (int i=n-3; i>=0; i--){
            a[i] = max(a[i+1], a[i] + a[i+2]);
        }

        return a[0];
    }
};
