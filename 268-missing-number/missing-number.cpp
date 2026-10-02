class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /*
            [3,0,1] = n = 3
             
             count = n + 1
             count = [1,1,0,1]

             

        */

        int lenght = nums.size();

        std::vector<int> count(lenght + 1, 0);

        for (int num : nums){
            count[num]++;
        }

        for (int i {}; i < count.size(); i++){
            if (count[i] == 0){
                return i;
            }
        }

        return -1;
    }
};