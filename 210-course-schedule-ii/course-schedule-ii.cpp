class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        /*
        numCourses = 3, prerequisites = [[0,1],[1,2],[2,0]]
            
            2 - 1 - 0 - 2   not possible 

        numCourses = 3, prerequisites = [[1,0]]
            0 - 1

        indegrees = [0 : 0, 1 : 1, 2 : 0]
        graph = [0:1]

        q = 0, 2
        0, result = [0], indegree[1] = 0, 
        q = 2, 1
        2, result = [0, 2]
        q = 1
        1, result = [0, 2, 1]

        result.size = numCourses
        */

        std::unordered_map<int, std::vector<int>> graph;
        std::unordered_map<int, int> indegrees;
        std::queue<int> q;
        std::vector<int> result;

        for (int i {}; i < numCourses; i++){
            indegrees[i] = 0;
        }

        for (auto& entry : prerequisites){  
            int after = entry[0];
            int before = entry[1];
            graph[before].push_back(after);
            indegrees[after]++;
        }

        for (auto [key, val]: indegrees){
            if (val == 0){
                q.push(key);
            }
        }

        while (!q.empty()){
            int n = q.size();
            for (int i {}; i < n; i++){
                int course = q.front();
                q.pop();

                result.push_back(course);

                for (const int nei : graph[course]){
                    indegrees[nei]--;

                    if (indegrees[nei] == 0){
                        q.push(nei);
                    }
                }
            }
        }

        if (numCourses == result.size()){
            return result;
        }
        else{
            return {};
        }

    }
};