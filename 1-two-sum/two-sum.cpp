class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> hashmap;

        for (int i {}; i < nums.size(); i++){
            int diff = target - nums[i];
            if (hashmap.count(diff)){
                int index = hashmap[diff];
                return {index, i};
            }
            hashmap[nums[i]] = i;
        }

        return {};
    }
};