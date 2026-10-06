class Solution {
public:
    int compress(vector<char>& chars) {
        /*
        begin with an empty string s. 
        
        for each group of consecutive repeating chars:
        - if the group length is 1, append the character to s
        - otherwise append the char followed by the groups length

        the string s should not be returned seperately, but instead be stored in the input char array chars. 
        group lenghts that are 10 or longer will be split into multiple chars in chars 

        constant space
        the chars in the array beyond the returned length do not matter and should be ignored.

        chars = ["a","a","b","b","c","c","c"]
                  lr
                  l   r
                  l       r                   

        */

        int write = 0;
        int read = 0;

        while (read < chars.size()){
            char current_char = chars[read];
            int count = 0;

            while (read < chars.size() && chars[read] == current_char){
                count++;
                read++;
            }

            chars[write] = current_char;
            write++;

            if (count > 1){
                for (char c : std::to_string(count)){
                    chars[write] = c;
                    write++;
                }
            }
        }

        chars.resize(write);
        return chars.size();


    }
};