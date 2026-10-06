class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        /*  
            prefix = 6
            res =  [0, 1, 3, 6, 0]
                             i
            nums = [1, 2, 3, 4]
            


        */

        
        std::deque<int> res(nums.size() + 1, 0);

        for (int i {}; i < nums.size(); i++){
            res[i+1] = res[i] + nums[i];
        }


        res.pop_front();
        std::vector<int> result(res.begin(), res.end());
        return result;
    }
};