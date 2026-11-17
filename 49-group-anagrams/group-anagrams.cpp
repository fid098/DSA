class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        std::unordered_map<std::string, std::vector<std::string>> hashgroup;
        std::vector<std::vector<std::string>> result;

        for (int i {}; i < strs.size(); i++){
            std::string count(26,0);
            for (char c : strs[i]){
                count[c - 'a']++;
            }
            hashgroup[count].push_back(strs[i]);
        }

        for (const auto& [key, val] : hashgroup){
            result.push_back(val);
        }

        return result;
    }
};