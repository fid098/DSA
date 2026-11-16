class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        /*
            given an array nums of lenght n
            - create and array ans with lenght 2n
            - ans[i] == nums[i] and ans[i + n] == nums[i]

            ans = [0,0,0,0,0,0]
                   i
            i = 0 + 3 = 3 mod 3 = 0
            i = 1 + 3 = 4 mod 3 = 1
            i = 2 + 3 = 5 mod 3 = 2
            i = 3 + 3 = 6 mod 3 = 0
            i = 4 + 3 = 7 mod 3 = 1
            i = 5 + 3 = 8 mod 3 = 2

            nums = [1,2,1]
        */
        int n = nums.size();
        std::vector<int> ans(2*n, 0);
        for (int i {}; i < ans.size(); i++){
            int index = (i + n) % n;
            ans[i] = nums[index];
        }

        return ans;
    }
};