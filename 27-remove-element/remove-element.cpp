class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        /*
            given an integer array nums and an integer val
            - remove all occurences of val in nums in place
            - return the number of elements in nums which are not equal to val

            - the first k elements in nums should contain the elements which are not equal to val
            - return k

            nums = [3,2,2,3], val = 3
                    w r
                    w = 3, val = w, r++, if (r != val) w = nums[r], k = 1

            nums = [0,1,3,0,2,2,4,2], val = 2
                          r   w  
        */
        int r = 0;

        for (int w {}; w < nums.size(); w++){
            if (nums[w] != val){
                std::swap(nums[r], nums[w]);
                r++;
            }
        }

        return r;

    }
};