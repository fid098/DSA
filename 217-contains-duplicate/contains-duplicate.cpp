class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        /*
            given integer array nums 
            return true if any value appears at least twice, and return false if every element is distinct
        */

        std::unordered_map<int, int> count;
        for (int i {}; i < nums.size(); i++){
            int num = nums[i];
            count[num]++;
            if (count[num] > 1){
                return true;
            }
        }
        return false;
    }
};