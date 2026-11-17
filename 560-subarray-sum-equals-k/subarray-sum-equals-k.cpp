class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        std::unordered_map<int, int> prefix_counts;
        prefix_counts[0] = 1;

        int curr_sum = 0;
        int total_subarrays = 0;

        for (int num : nums){
            curr_sum += num;

            int check = curr_sum - k;
            if (prefix_counts.count(check)){
                total_subarrays += prefix_counts[check];
            }

            prefix_counts[curr_sum]++;
        }

        return total_subarrays;
    }
};