class Solution {
public:
    bool wordPattern(string pattern, string s) {
        /*  
        "dog cat cat fish"    "abba"
             l  r
        index = 1
        word = cat
        letter = b
        lToW = {a:dog, b:cat}
        WTol = {dog:a, }
        


        */
        std::stringstream ss(s);
        std::vector<std::string> words;
        std::string word;

        while (ss >> word) {
            words.push_back(word);
        }

        if (pattern.length() != words.size()) {
            return false;
        }

        std::unordered_map<char, std::string> lToW;
        std::unordered_map<std::string, char> WTol;

        int index = 0;
        int left = 0;
        for (const std::string w : words){
                char letter = pattern[index];
    
                auto it1 = lToW.find(letter);
                auto it2 = WTol.find(w);

                if (it1 != lToW.end() && it1->second != w){
                    return false;
                }
                if (it2 != WTol.end() && it2->second != letter){
                    return false;
                }

                lToW[letter] = w;
                WTol[w] = letter;

                index++;
        }

        return true;
    }
};