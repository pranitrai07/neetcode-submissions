class Solution {
public:
        int checker(int i, int j, string& s, int len){
        int n = s.size(), sm=0;
        while (i>=0 && j<n && s[i] == s[j]){
            i--;
            j++;
            sm++;
        }
        
        return sm;
    }

    int countSubstrings(string& s) {
        int mx = 0, n = s.size(), ans=0;

        for (int ind=0; ind<n; ind++){
            ans += checker(ind, ind+1, s, mx);
            ans += checker(ind, ind, s, mx);
        }

        return ans;
    }
};
