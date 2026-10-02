class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /*
            [3, 0, 1]
             i           i++
            [3, 0, 1]
                i        nums[i] != i so swap 0 with nums[0]
            [0, 3, 1]
                   i     nums[i] != i so swap 1 with nums[1]
            [0, 1, 3]

            then go through, if any number is not equal to its index - 1, return index - 1

            
            [3, 0, 1]
             i         i < 3, 3 not < 3 so else block
                i      i < 3, 0 < 3 and 0 != 1 so swap 
            [0, 3, 1]
                   i   i < 3, 1 < 3 and 1 != 2 so swap 
            [0, 1, 3]        
              


        */

        int i {};

        while (i < nums.size()){
            if (nums[i] < nums.size() && nums[i] != i){
                std::swap(nums[i], nums[nums[i]]);
            }
            else{
                i++;
            }
        }

        for (int i {}; i < nums.size(); i++){
            if (nums[i] != i){
                return i;
            }
        }

        return nums.size();
    }
};