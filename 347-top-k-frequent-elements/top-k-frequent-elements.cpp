class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::vector<int> result;
       std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>> minheap;
        std::unordered_map<int, int> hashmap;

        for (int i {}; i < nums.size(); i++){
            hashmap[nums[i]]++;
        }

        for (const auto& [key, value] : hashmap){
            minheap.push({value, key});
        }

        for (int i {}; i < k; i++){
            std::pair<int, int> res = minheap.top(); minheap.pop();
            int num = res.second;
            result.push_back(num);
        }

        return result;
    }
};