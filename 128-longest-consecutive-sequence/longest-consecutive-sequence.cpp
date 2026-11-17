class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest {};

        std::unordered_set<int> hashset;
        for (int num : nums){
            hashset.insert(num);
        }

        for (int num : hashset){
            if (!hashset.contains(num - 1)){
                int current = num;
                int lenght = 1;
                while (hashset.contains(current + 1)){
                    current++;
                    lenght++;
                }
                longest = std::max(longest, lenght);
            }
        }
        return longest;
    }
};