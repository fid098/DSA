class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        /*
            n people labelled 1 - n
            1 of these are secretely the town judge
            -if judge exists, they trust nobody
            -everybody except town judge trusts the town judge
            -only 1 person that satisfies 1 and 2

            [[1,3],[2,3],[3,1]]

           
    

        */
        int ans = -1;

        std::unordered_map<int, int> indegrees;
        std::unordered_map<int, int> outdegrees;
        for (int i {0}; i < n; i++){
            indegrees[i+1] = 0;
            outdegrees[i+1] = 0;
        }

        std::unordered_map<int, std::vector<int>> graph;
        for (auto& tr : trust){
            int trustee = tr[0];
            int trusted = tr[1];
            graph[trusted].push_back(trustee);
            indegrees[trusted]++;
            outdegrees[trustee]++;
        }

        for (int i {0}; i < n; i++){
            if (indegrees[i+1] == n - 1 && outdegrees[i+1] == 0){
                ans = i+1;
            }
        }

        return ans;
    }

};