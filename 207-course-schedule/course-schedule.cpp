class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        /*
        from prerequisites, get indegrees and graph hashmaps 
        Input: n = 2, prerequisites = [[0, 1]]
           0 -- 1
        graph = {0:1}
        course_count = 0
        in degrees = {0:0, 1:1}
        queue[0] = pop 0; count += 1, indegrees = {1:0}
        queue[1] = pop 1; count += 1, nothing in indegrees, return count == n

        Input: n = 2, prerequisites = [[0, 1], [1, 0]]
           0 -- 1, 1 -- 0
        graph = {0:1, 1:0}
        indegrees = {0:1, 1:1}
        no course with indegrees == 0;
        return false;
    */

        std::unordered_map<int, std::vector<int>> graph;
        std::unordered_map<int, int> indegrees;
        std::queue<int> q;

        //load indegrees with zero first 
        for (int i {0}; i < numCourses; i++){
            indegrees[i] = 0;
        }

        //load graph and indegrees
        for (auto& preq : prerequisites){
            int before = preq[0];
            int after = preq[1];
            graph[after].push_back(before);
            indegrees[before]++;
        }

        //push isolated nodes to queue
        for (const auto& [course, deg] : indegrees) {
            if (deg == 0) {
                q.push(course);
            }
        }

        //if we have a cycle with nodes with 0 indegrees
        if (q.empty()){
            return false;
        }

        //while not empty 
        int course_count {0};
        while (!q.empty()){
            int course = q.front();
            q.pop();
            course_count++;
            for (int next : graph[course]){
                indegrees[next]--;
                if (indegrees[next] == 0){
                    q.push(next);
                }
            }
        }
        
        
        return course_count == numCourses;
    }
};