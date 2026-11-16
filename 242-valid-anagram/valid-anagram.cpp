class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()){
            return false;
        }

        std::vector<int> count(26, 0);
        for (int i {}; i < s.size(); i++){
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for (int i {}; i < count.size(); i++){
            if (count[i] != 0){
                return false;
            }
        }
        return true;
    }
};