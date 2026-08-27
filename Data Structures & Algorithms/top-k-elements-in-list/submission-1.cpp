class Solution {
public:
    vector<int> topKFrequent(vector<int>& a, int k) {
        int n = a.size();
        vector<int> f(2001);
        for (int i=0; i<n; i++) f[a[i] + 1000]++;

        vector<pair<int, int>> vp;
        for (int i=0; i<=2000; i++){
            if (f[i] > 0){
                vp.push_back({f[i], i - 1000});
            }
        }

        sort(vp.begin(), vp.end(), greater<pair<int, int>>());

        vector<int> ans;
        for (int i=0; i<k; i++) ans.push_back(vp[i].second);
        return ans;
    }
};
