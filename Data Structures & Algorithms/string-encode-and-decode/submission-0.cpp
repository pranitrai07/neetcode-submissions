class Solution {
public:
    string encode(vector<string>& strs) {
        string ans;
        for (auto s: strs){
            for (auto x: s){
                ans += x;
                ans += x;
            }
            ans += '.';
            ans += '-';
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> vec;
        string cur;
        for (int i=0; i<s.size(); i+=2){
            if (s[i] == s[i+1]){
                cur += s[i];
            } else {
                vec.push_back(cur);
                cur = "";
            }
        }
        return vec;
    }
};
