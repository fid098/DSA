class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        /*
            given an integer array nums of n elements and an integer k

            find a contiguous subarray whose lenght is equal to k that has the maximum average value and return the value 

            [1,12,-5,-6,50,3], k = 4
             lr                       cur_sum = 1; not in the while condition so continue
             l r                      cur_sum = 13; not in the while condition so continue
             l    r                   cur_sum = 8; not in the while condition
             l        r               cur_sum = -2; (3 - 0 + 1) not > k so continue
             l          r             cur_sum = 48; in (4-0+1) > k; cur_sum = 47



        */

        long long max_sum = INT_MIN;
        long long cur_sum {};

        int left = 0;
        

        for (int right{}; right<nums.size(); right++){
            cur_sum += nums[right];

            while (right - left + 1 > k){
            cur_sum -= nums[left];
            left++;
           }

           if (right - left + 1 == k){
            max_sum = std::max(max_sum, cur_sum);
           }

        }

        return (double)max_sum / k;

    }
};