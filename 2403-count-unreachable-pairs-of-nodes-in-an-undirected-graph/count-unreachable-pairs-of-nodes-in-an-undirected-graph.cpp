class Solution {
private:
    std::vector<int> parent;
    std::vector<int> size;
    
    int find(int x){
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
        if (size[rx] < size[ry]){
            swap(rx, ry);
        }
        parent[ry] = rx;
        size[rx] += size[ry];
        return true;
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        size.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
        
        std::vector<int> comp_size;
        
        for (auto edge : edges){
            unite(edge[0], edge[1]);
        }
        
        for (int i {}; i < n; i++){
            if (find(i) == i){
                comp_size.push_back(size[i]);
            }
        }
        
        long long seen {};
        long long res {};
        for (int i {}; i < comp_size.size(); i++){
            res += static_cast<long long>((comp_size[i])) * seen;
            seen += comp_size[i];
        }
        
        return res;
        
        
    }
};