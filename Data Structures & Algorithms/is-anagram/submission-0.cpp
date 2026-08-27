class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> f(26);
        for (auto x: s) f[x-'a']++;
        for (auto x: t) f[x-'a']--;

        for (auto x: f){
            if (x != 0) return false;
        }
        return true;
    }
};
