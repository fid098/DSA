class Solution {
private:
    bool dfs(int node, std::unordered_map<int, std::vector<int>>& graph, std::unordered_set<int>& visited, int destination){
        //if we reach destination
        if (node == destination){
            return true;
        }
        
        //if not at destination and theirs neighbours to go to, add to visited and then dfs on neighbours
        visited.insert(node);
        for (const int nei : graph[node]){
            if (!visited.count(nei)){
                if (dfs(nei, graph, visited, destination)){
                    return true;
                }
            }
            else{
                continue;
            }
        }
        
        return false;
        
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        /*
        n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
        {0:{1,2}, 1:{0,2}, 2:{0,1}}
        visited = []
        
        source = 0
        dfs(0) = node != destination
        visited = [0]
        loop through neighbours : dfs(1)
        node != destination
        visited = [0,1]
        loop through neighbours : dfs(0)
        node != destination
        
        
        */
        std::unordered_map<int, std::vector<int>> graph;
        std::unordered_set<int> visited;
        
        for (auto entry: edges){
            int before = entry[0];
            int after = entry[1];
            graph[before].push_back(after);
            graph[after].push_back(before);
        }
        
        return dfs(source, graph, visited, destination);
    }
};