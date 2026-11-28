class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        //[a,b] means a to b
        std::unordered_map<int, std::vector<int>> graph;
        std::unordered_set<int> visited;
        std::set<std::pair<int, int>> connect;
        std::queue<int> q;
        q.push(0);
        visited.insert(0);
        int count {};
        
        for (auto entry : connections){
            graph[entry[0]].push_back(entry[1]);
            graph[entry[1]].push_back(entry[0]);
        }
        
        for (auto entry : connections){
            connect.insert({entry[0], entry[1]});
        }
        
        while (!q.empty()){
            int n = q.size();
            for (int i {}; i < n; i++){
                int node = q.front();
                q.pop();
                
                for (auto nei : graph[node]){
                    if (!visited.count(nei)){
                        q.push(nei);
                        visited.insert(nei);
                        
                        if (!connect.contains({nei,node})){
                            count++;
                        }
                    }
                }
            }
        }
        
        return count;
        
    }
};