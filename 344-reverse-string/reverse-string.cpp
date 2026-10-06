class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right){
            if (s[left] != s[right]){
                std::swap(s[left], s[right]);
                left++;
                right--;
            }
            else{
                left++;
                right--;
            }
        }

    }
};