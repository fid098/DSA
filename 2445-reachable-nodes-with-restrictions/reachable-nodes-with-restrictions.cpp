class Solution {
private:
    void dfs(int node, int& max_num, std::unordered_set<int>& seen, std::unordered_set<int>& cannot, std::unordered_map<int, std::vector<int>>& graph){
        if (cannot.count(node)){
            return;
        }
        
        max_num++;
        seen.insert(node);
        for (const int nei : graph[node]){
            if (!seen.count(nei)){
                dfs(nei, max_num, seen, cannot, graph);
            }
        }
        
        return;
    }
    
    
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        std::unordered_map<int, std::vector<int>> graph;
        std::unordered_set<int> seen;
        std::unordered_set<int> cannot(restricted.begin(), restricted.end());
        int max_num {};
        
        for (auto edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        dfs(0, max_num, seen, cannot, graph);
        return max_num;
        
    }
};