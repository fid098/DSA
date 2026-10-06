class Solution {
public:
    int minSwaps(string s) {
        /*
            given a binary string s, return the minimum number of character swaps to make it alternating or -1 if impossible 

            with the lenght of s * 2 to cover all substrings
            generate two alternating versions that either start with 0 or 1 

            use a window and loop through s * 2 and find any differences between the window and either of the two alternating

            return the minimum difference

            s    = 1 1 1 0 0 0 1 1 1 0 0 0
            alt1 = 0 1 0 1 0 1 0 1 0 1 0 1
            alt2 = 1 0 1 0 1 0 1 0 1 0 1 0
                     l         r

            diff1 = 3
            diff2 = 2

            res = 2


        */

        int ones {};
        int zeros {};

        for (int i {}; i < s.size(); i++){
            if (s[i] == '1'){ones++;}
            if (s[i] == '0'){zeros++;} 
        }

        if (std::abs(ones - zeros) > 1){
            return -1;
        }

        int diff1 = 0;
        int diff2 = 0;

        for (int i = 0; i < s.size(); i++){
            char a1 = (i % 2 == 0) ? '0' : '1';
            char a2 = (i % 2 == 0) ? '1' : '0';
            if (s[i] != a1) {diff1++;}
            if (s[i] != a2) {diff2++;}
        }

        if (ones > zeros) return diff2 / 2;  //must start with 1
        if (zeros > ones) return diff1 / 2;   //must start with 0
        return min(diff1, diff2) / 2;
        
    }
};