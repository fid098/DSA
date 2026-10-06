class Solution {
public:
    int minFlips(string s) {
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

        int n = s.size();
        s = s + s;
        int len = s.size();

        std::string alt1 = "";
        std::string alt2 = "";

        int res = INT_MAX;
        int diff1 {};
        int diff2 {};

        for (int i {}; i < len; i++){
             (i % 2 == 0) ? alt1 += '0' : alt1 += '1';
             (i % 2 == 0) ? alt2 += '1' : alt2 += '0';
        }

        int left {};
        for (int right {}; right < len; right++){
            if (s[right] != alt1[right]){diff1++;}
            if (s[right] != alt2[right]){diff2++;}

            if (right - left + 1 > n){
                if (s[left] != alt1[left]){diff1--;}
                if (s[left] != alt2[left]){diff2--;}
                left++;
            }

            if (right - left + 1 == n){
                int diff = std::min(diff1, diff2);
                res = std::min(res, diff);
            }
        }

        return res;
    }
};