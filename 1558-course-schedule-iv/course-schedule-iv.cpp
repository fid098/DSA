class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        /*
            numCourses = 4, prerequisites = [[1,0],[2,1],[3,2]], queries = [[0,1],[3,1]]
            3 - 2 - 1 - 0 

            3 

        */
        std::unordered_map<int, std::vector<int>> graph(numCourses);
        std::unordered_map<int, int> indegrees;
        std::queue<int> q;
        std::vector<std::unordered_set<int>> prereq(numCourses);

        for (int i {}; i < numCourses; i++){
            indegrees[i] = 0;
        }

        for (auto entry: prerequisites){
            int before = entry[0];
            int after = entry[1];
            graph[before].push_back(after);
            indegrees[after]++;
        }

        for (auto [key, val] : indegrees){
            if (val == 0){
                q.push(key);
            }
        }

        while (!q.empty()){
            int n = q.size();
            for (int i {}; i < n; i++){
                int course = q.front();
                q.pop();

                //prerequisite of nei is course
                for (const int nei : graph[course]){
                    prereq[nei].insert(course);

                    //prerequisite of nei is also prerequisite of course
                    for (int p : prereq[course]){
                        prereq[nei].insert(p);
                    }

                    indegrees[nei]--;

                    if (indegrees[nei] == 0){
                        q.push(nei);
                    }
                }
            }
        }

        std::vector<bool> result;
        for (auto query : queries){
            int pre = query[0];
            int post = query[1];
            result.push_back(prereq[post].contains(pre));
        }

        return result;
        
    }
};