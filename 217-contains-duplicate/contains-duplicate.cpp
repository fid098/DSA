class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        /*
            given integer array nums 
            return true if any value appears at least twice, and return false if every element is distinct
        */

        unordered_set<int> seen;
        for (int i {}; i < nums.size(); i++){
            if (seen.contains(nums[i])){
                return true;
            }
            seen.insert(nums[i]);
        }

        return false;
    }
};