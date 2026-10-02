class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*  
            apparently boyer moore voting algorithm 

            candidate = 0
            count = 0
            
            [3,2,3]
             i        count == 0; candidate = 3, candidate == num, count = 1
               i      count != 0; candidate != 2, count = 0
                 i    count == 0; candidate = 3, candiate == num, count = 1

            return candidate = 3


            [2,2,1,1,1,2,2]
             i               count = 0, candidate = num, candidate == 2, count = 1
               i             count != 0, candidate = num, count = 2
                 i           count != 0, candidate != num, count = 1
                   i         count != 0, candidate != num, count = 0
                     i       count == 0, candidate = num, candidate = 0, count = 1
                       i     count != 0, candidate != num, count = 0
                         i   count == 0, candidate = num, candidate == 2, count = 1

            return candidate = 2  
        */

        int candidate {};
        int count {};

        for (int i {}; i < nums.size(); i++){
            if (count == 0){
                candidate = nums[i];
            }

            if (nums[i] == candidate){
                count++;
            }
            else{
                count--;
            }
        }

        return candidate;
    }
};