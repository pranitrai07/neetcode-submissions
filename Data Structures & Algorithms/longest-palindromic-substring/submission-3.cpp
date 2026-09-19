class Solution {
public:
    string checker(int i, int j, string& s, int len){
        int n = s.size();
        while (i>=0 && j<n && s[i] == s[j]){
            i--;
            j++;
        }

        if ((j-i-1) <= len) return "";
        
        return s.substr(i+1, j-i-1);
    }

    string longestPalindrome(string s) {
        int mx = 0, n = s.size();
        string ans = "";

        for (int ind=0; ind<n; ind++){
            string p = checker(ind, ind+1, s, mx);
            if (p.size() > mx){
                mx = p.size();
                ans = p;
            }

            p = checker(ind, ind, s, mx);
            if (p.size() > mx){
                mx = p.size();
                ans = p;
            }
        }

        return ans;
    }
};
