class Solution {
public:
    vector<int> topKFrequent(vector<int>& a, int k) {
        int n = a.size();
        sort(a.begin(), a.end(), greater<int>());

        vector<pair<int, int>> vp;

        int i=0;
        while (i<n){
            int j = i+1;
            while (j<n && a[j] == a[i]) j++;

            vp.push_back({j-i, a[i]});
            i = j;
        }

        sort(vp.begin(), vp.end(), greater<pair<int, int>>());

        vector<int> ans;
        for (int i=0; i<k; i++){
            ans.push_back(vp[i].second);
        }
        return ans;
    }
};
