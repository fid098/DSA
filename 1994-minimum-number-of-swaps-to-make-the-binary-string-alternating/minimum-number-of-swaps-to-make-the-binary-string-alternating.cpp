class Solution {
public:
    int minSwaps(string s) {
        /*
            given a binary string s, return the minimum number of character swaps to make it alternating or -1 if impossible 

        */

        int ones = count(s.begin(), s.end(), '1');
        int zeros = s.size() - ones;
        if (abs(ones - zeros) > 1) return -1;

        auto cost = [&](char start) {
            int mismatch = 0;
            for (int i = 0; i < s.size(); i++) {
                char expected = (i % 2 == 0) ? start : (start == '0' ? '1' : '0');
                if (s[i] != expected) mismatch++;
            }
            return mismatch / 2;
        };

        if (ones > zeros) return cost('1');
        if (zeros > ones) return cost('0');
        return min(cost('0'), cost('1'));


    }
};