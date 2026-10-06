class Solution {
public:
    int firstUniqChar(string s) {
        /*

            {l: 1
             e: 3
             t: 1
             c: 1
             o: 1
             d: 1)
        */

        std::unordered_map<char, int> hashmap;
        std::set<char> characters;

        for (char c : s){
            hashmap[c]++;
        }

        for (const auto& [key, val] : hashmap){
            if (val == 1){
                characters.insert(key);
            }
        }

        for (int i {}; i < s.size(); i++){
            if (characters.count(s[i])){
                return i;
            }
        }

        return -1;
    }
};