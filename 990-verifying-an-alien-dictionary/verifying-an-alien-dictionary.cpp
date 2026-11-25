class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        std::unordered_map<char, int> orderInt;

        for (int i {}; i < order.size(); i++){
            orderInt[order[i]] = i;
        }

        for (int j {}; j < words.size() - 1; j++){
            std::string word1 = words[j];
            std::string word2 = words[j + 1];

            for (int k {}; k < word1.size(); k++){
                if (k == word2.size()){
                    return false;
                }

                if (word1[k] != word2[k]){
                    if (orderInt[word1[k]] > orderInt[word2[k]]){
                        return false;
                    }
                    break;
                }
            }
        }

        return true;
    }
};