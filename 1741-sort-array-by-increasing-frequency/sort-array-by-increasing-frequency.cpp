class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        /*
            given an array of integers, sort the array in increasing order, based on the frequency of values
            if multiple values have the same frequency, sort them in decreasing order 

            [1,1,2,2,2,3]
            count = {1:2, 2:3, 3:1}

        */

        std::unordered_map<int, int> count;

        for (int i {}; i < nums.size(); i++){
            count[nums[i]]++;
        }

        std::sort(nums.begin(), nums.end(), [&](int a, int b){
            return count[a] != count[b] ? count[a] < count[b] : a > b;
        });

        return nums;
    }
};