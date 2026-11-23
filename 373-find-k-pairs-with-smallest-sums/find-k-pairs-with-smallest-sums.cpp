class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        using Entry = std::array<int, 3>;
        std::priority_queue<Entry, std::vector<Entry>, std::greater<Entry>> minheap;

        int n1 = nums1.size();
        int n2 = nums2.size();

        for (int i {}; i < std::min(n1, k); i++){
            minheap.push({nums1[i] + nums2[0], i , 0});
        }

        std::vector<std::vector<int>> result;

        while (result.size() < k && !minheap.empty()){
            auto [sum, i, j] = minheap.top();
            minheap.pop();

            result.push_back({nums1[i], nums2[j]});

            if (j + 1 < nums2.size()){
                minheap.push({nums1[i] + nums2[j + 1], i, j + 1});
            }
        }

        return result;
    }
};