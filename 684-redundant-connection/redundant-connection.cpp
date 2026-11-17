class Solution {
public:
    std::unordered_map<int, int> parent;

    void add(int x){
        if (!parent.contains(x)){
            parent[x] = x;
        }
    }

    int find(int x){
        add(x);
        if (parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int x, int y){
        int rx = find(x);
        int ry = find(y);
        if (rx == ry){
            return false;
        }
        parent[ry] = rx; 
        return true;   
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        /*
            n nodes labeled 1 - n
            - one additional edge added that has two different vertices chosen from 1 - n
            - was not an edge that already existed
            - we are given an array edges of length n
            - edges[i] = [ai, bi] there is an edge between ai and bi

            return an edge that can be removed so that the graph is a tree of n nodes 

              1(root) -- 2 -- 3
              |
              |
              3

              in the case of (2, 3)
              if they already have the same root, return 


              5 -- 1(root) -- 2 -- 3 -- 4
                    |
                    |
                    4
             in the case of (1,4)
             if they already have the same root then return edge

        */
    for (auto& edge : edges){
        if (!unite(edge[0], edge[1])){
            return edge;
        }
    }

    return {};
}
};