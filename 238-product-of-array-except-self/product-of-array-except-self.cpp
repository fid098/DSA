class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*
    prefix =   [1,1,2,6]
        nums = [1,2,3,4]
    postfix =  [24,12,4,1]
    result =   [24,12,8,6]
        */
    std::vector<int> result(nums.size(), 1);
    int prefix = 1;
    for (int i {}; i < nums.size(); i++){
        result[i] = prefix;
        prefix = prefix * nums[i];
    }

    int postfix = 1;
    for (int i = nums.size() - 1; i >= 0; i--){
        result[i] = postfix * result[i];
        postfix = postfix * nums[i];
    }

    return result;

    }
};