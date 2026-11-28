class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        /*
            1 indexed number of nodes
            [[1,2],[2,3],[4,2]]
            
            {1:[2], 2:[1,3,4], 3:[2], 4:[2]}
            
            [[1,2],[5,1],[1,3],[1,4]]
            {1:[2,5,3,4], 2:[1], 5:[1], 3:[1], 4:[1]}
        */
        
        std::unordered_map<int, std::vector<int>> graph;
        
        for (auto entry : edges){
            graph[entry[0]].push_back(entry[1]);
            graph[entry[1]].push_back(entry[0]);
        }
        
        
        for (auto [key, val] : graph){
            if (val.size() == edges.size()){
                return key;
            }
        }
        
        return -1;
    }
};