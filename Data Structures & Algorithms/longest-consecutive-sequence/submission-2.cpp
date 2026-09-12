class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int n = nums.size();
        map<int, int> mp, fl;
        for (auto x: nums) mp[x]++;

        int l=nums[0], r=nums[0], mx = 1;
        for (auto x: nums){
            if (fl[x]) continue;

            fl[x] = 1;
            int p = x+1;
            while (mp[p]) {
                fl[p] = 1;
                p++;
            }
            int r1 = p-1;

            p = x-1;
            while (mp[p]) {
                fl[p] = 1;
                p--;
            }
            int l1 = p+1;

            int len = r1-l1+1;
            if (len > mx){
                mx = len;
                l = l1;
                r = r1;
            }
        }

        return mx;
    }
};
