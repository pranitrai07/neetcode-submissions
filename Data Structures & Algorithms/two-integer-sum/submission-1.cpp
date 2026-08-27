class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        for (int i=0; i<nums.size(); i++) {
            int p = target - nums[i];

            if (mp.count(p)) {
                return {mp[p], i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};
