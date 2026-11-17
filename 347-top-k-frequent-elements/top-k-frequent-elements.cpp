class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::vector<int> result;
       priority_queue<std::pair<int, int>,vector<std::pair<int, int>>,greater<std::pair<int, int>>> minheap;
        std::unordered_map<int, int> hashmap;

        for (int i {}; i < nums.size(); i++){
            hashmap[nums[i]]++;
        }

        for (const auto& [key, value] : hashmap){
            minheap.push({value, key});
            if (minheap.size() > k){
                minheap.pop();  //remove the little ones
            }
        }

        while(!minheap.empty()){
            result.push_back(minheap.top().second);
            minheap.pop();
        }

        return result;
    }
};