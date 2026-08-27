class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& vec) {
        vector<vector<string>> ans;
        map<string, vector<string>> mp;

        for (auto str: vec){
            string s(26, '0');
            for (auto ch: str){
                s[ch-'a']++;
            }
            mp[s].push_back(str);
        }

        for (auto [s, v]: mp){
            ans.push_back(v);
        }
        return ans;
    }
};
