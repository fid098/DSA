class Solution {
public:
    string frequencySort(string s) {

        std::unordered_map<char, int> count;

        for (char c : s){
            count[c]++;
        }

        std::sort(s.begin(), s.end(), [&](char a, char b){
            return count[a] != count[b] ? count[a] > count[b] : a < b;
        });

        return s;

    }
};