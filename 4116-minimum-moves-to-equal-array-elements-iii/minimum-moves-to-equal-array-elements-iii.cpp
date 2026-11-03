class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max_num = *max_element(nums.begin(), nums.end());
        int result {};
        for (int num : nums){
            result += max_num - num;
        }

        return result;
    }
};