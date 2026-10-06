class Solution {
public:
    int minimumSwap(string s1, string s2) {
        /*
            given two strings s1 and s2 of equal length consisting of letters x and y only
            -make these two strings equal to eachother. you can swap any two characters that belong to different strings
            so s1[0] and s2[j]

            return the minimum number of swaps 

            -ignore every index where s1[i] = s2[i]
            -each mismatch is one of two types s1 has x and s2 has y or s1 has y and s2 has x
            

        */

        if (s1.size() != s2.size()){
            return -1;
        }


        int xy {};
        int yx {};

        for (int i {}; i < s1.size(); i++){
            if (s1[i] == 'x' && s2[i] == 'y'){
                xy++;
            }
            else if (s1[i] == 'y' && s2[i] == 'x'){
                yx++;
            }
        } 

        if ((xy + yx) % 2 == 1){
                return -1;
        }

        return xy/2 + yx/2 + 2 * (xy%2);

        

    }
};