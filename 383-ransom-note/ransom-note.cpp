class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::unordered_map<char, int> bank;

        for (int i {}; i < magazine.size(); i++){
            bank[magazine[i]]++;
        }

        for (int i {}; i < ransomNote.size(); i++){
            bank[ransomNote[i]]--;
        }

        for (auto [letter, count] : bank){
            if (count < 0){
                return false;
            }
        }

        return true;
    }
};