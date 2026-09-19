class Solution {
public:
    string checker(int i, int j, string& s){
        int n = s.size();
        string p = "";
        while (i>=0 && j<n && s[i] == s[j]){
            i--;
            j++;
        }
        
        for (int ind=i+1; ind<j; ind++) p += s[ind];
        return p;
    }

    string longestPalindrome(string s) {
        int mx = 0, n = s.size();
        string ans = "";

        for (int ind=0; ind<n; ind++){
            string p = checker(ind, ind+1, s);
            if (p.size() > mx){
                mx = p.size();
                ans = p;
            }

            p = checker(ind, ind, s);
            if (p.size() > mx){
                mx = p.size();
                ans = p;
            }
        }

        return ans;
    }
};
