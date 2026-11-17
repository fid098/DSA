class MyHashSet {
private: 
    std::vector<int> HashSet;
public:
    MyHashSet() {}
    
    void add(int key) {
        if (std::find(HashSet.begin(), HashSet.end(), key) == HashSet.end()){
            HashSet.push_back(key);
        }
    }
    
    void remove(int key) {
        std::erase(HashSet, key);
    }
    
    bool contains(int key) {
        return std::find(HashSet.begin(), HashSet.end(), key) != HashSet.end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */