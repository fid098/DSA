class Solution {
private: 
    void reverse(std::string &s, int left, int right){
        while (left < right){
            std::swap(s[left], s[right]);
            left++;
            right--;
        }
    }
public:
    string reverseWords(string s) {
        /*
            "  hello world  "
            reverse = "  drow olleh  "
                       j i
            i = 0, j = 0
            i < n, s[i] == ' ', i++
            start = j
            "drow olleh  "
                j=5, i=7
            reverse = 
            "word olleh  "
            j=5   i
            

        */
        int n = s.size();

        reverse(s, 0, n - 1);

        int i = 0;
        int j = 0;

        while (i < n){
            while (i < n && s[i] == ' '){
                i++;
            }

            if (i >= n){
                break;
            }

            if (j > 0){
                s[j++] = ' ';
            }

            int start = j;

            while (i < n && s[i] != ' '){
                s[j++] = s[i++];
            }

            reverse(s, start, j-1);
        }

        s.resize(j);

        return s;
    }
};