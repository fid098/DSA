class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::string res = "";

        for (int i {}; i < strs[0].size(); i++){
            for (std::string s : strs){
                if (i == s.size() || strs[0][i] != s[i]){
                    return res;
                }
            }
            res.push_back(strs[0][i]);
        }

        return res;
    }
};