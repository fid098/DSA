class Solution {
public:
    bool isIsomorphic(string s, string t) {
        /*
            if characters in s can be replaced to get t, they are isomorphic

        */

        if (s.size() != t.size()){
            return false;
        }

        std::unordered_map<char, char> bank1;
        std::unordered_map<char, char> bank2;

        for (int i {}; i < t.size(); i++){
            //if in the bank
            auto it1 = bank1.find(s[i]);
            auto it2 = bank2.find(t[i]);

            if (it1 != bank1.end() && it1->second != t[i]){return false;}
            if (it2 != bank2.end() && it2->second != s[i]){return false;}
            
            bank1[s[i]] = t[i];
            bank2[t[i]] = s[i];
        }

        return true;
    }
};