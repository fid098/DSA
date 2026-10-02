class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        /*
            res = []

            [4,3,2,7,8,2,3,1]
             i                 

        */

        std::vector<int> res;

        int i {};
        int n = nums.size();

        while (i < n){
            if (nums[i] != nums[nums[i] - 1]){
                std::swap(nums[i], nums[nums[i] - 1]);
            }
            else{
                i++;
            }
        }

        for (int j {}; j < nums.size(); j++){
            if (nums[j] != j + 1){
                res.push_back(j+1);
            }
        }

        return res;
    }
};