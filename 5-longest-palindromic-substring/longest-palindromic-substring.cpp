class Solution {
private:
    std::string expand_from_center(int left, int right, const std::string& s){
        while (left >= 0 && right < s.size() && s[left]==s[right]){
            left--;
            right++;
        }
        return s.substr(left+1, right-left-1);
    }
public:
    string longestPalindrome(string s) {
        /*
            max_pali = "bab"
            


            s = "b a b a d"
                
                start at each and expand outward 0(n2)

        */

        if (s.length() <= 1) {
            return s;
        }
        

        std::string max_str = s.substr(0, 1);

        for (int i = 0; i < s.length() - 1; i++) {
            std::string odd = expand_from_center(i, i, s);
            std::string even = expand_from_center(i, i + 1, s);

            if (odd.length() > max_str.length()) {
                max_str = odd;
            }
            if (even.length() > max_str.length()) {
                max_str = even;
            }
        }

        return max_str;
    }
};