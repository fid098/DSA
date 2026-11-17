class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*
            this is the boyer voting algorithm 

            whenever the count is 0 meaning equal number of numbers, then we update the candidate 

            if the candidate is the current number, then increment the count or we decrease the count


            count = 0
            candidate = 0

            nums = [3,2,3]
                    i       count = 0, candidate = 1, 1 == candidate so count = 1
                      i     count != 0, 2 != candidate so count = 0
                        i   count = 0, candidate = 3, 3 == candidate so count = 1
            
            return candidate
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