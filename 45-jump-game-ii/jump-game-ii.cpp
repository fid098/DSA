class Solution {
public:
    int jump(vector<int>& nums) {
        /*
            nums = [2,3,1,1,4]
                      i

                reach = 0
                i = 0, reach = max(0, 0+2) = 2, c = 1
                i = 1, reach = max(2, 1+3) = 4, c = 2, if reach == nums.size - 1,return c
            
            [2,3,0,1,4]

            reach = 0
            i = 0, reach = max(0, 0+2) = 2, c = 1
            i = 1, reach = max(2, 1 + 3) = 4, c = 2, reach == nums.size - 1, retun c

            wrong approach

            [2,3,1,1,4]
            lr           r < 4: left-right(0-0), furthest = max(0, 2), left = 1, jump = 1
               l r       r < 4: left-right(1-2), furthest = max(2, 1+3), left = 2, jump=2
                 l   r   r == nums.size() - 1 so return jumps 


        */

        int furthest {};

        int left {};
        int right {};
        int jumps {};

        if (nums.size() == 1){
            return 0;
        }

        while (right < nums.size() - 1){
            for (int i = left; i <= right; ++i){
                furthest = std::max(furthest, i + nums[i]);
            }
            left = right + 1;
            right = furthest;
            jumps++; 
        }

        return jumps;
    }
};