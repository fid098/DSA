class Solution {
private:
    void dfs(int node, std::vector<std::vector<int>>& AdjacencyList, std::vector<bool>& visited){
        //mark this node as visited and then visit all the nodes its connected to
        visited[node] = true;
        for (auto it : AdjacencyList[node]){
            if (visited[it] == false){
                dfs(it, AdjacencyList, visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        int count {};
        //create an adjacency list that holds all the connected nodes together 
        int n = isConnected.size();
        std::vector<std::vector<int>> AdjacencyList(n);
        for (int i {}; i < n; i++){
            for (int j {}; j < n; j++){
                if (isConnected[i][j] == 1 & i != j){
                    AdjacencyList[i].push_back(j);
                    AdjacencyList[j].push_back(i);
                }
            }
        }

        //visit the unvisited nodes in the adjacencylist and run dfs to get the number
        //of provinces
        std::vector<bool> visited(AdjacencyList.size(), false);
        for (int i {}; i < AdjacencyList.size(); i++){
            if (visited[i] == false){
                count++;
                dfs(i, AdjacencyList, visited);
            }
        }

        return count;
    }
};