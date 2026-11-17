class Solution {
public:
    std::vector<int> parent;

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

        parent[ry] = rx;
        return true;
    }


    bool equationsPossible(vector<string>& equations) {
        /*
            given an array of strings - equations 
            - represents relationships between variables 
            - each string is of lenght 4 and takes two forms 
            - xi == yi or xi != yi
            - both in lowercase, and they represent one letter variable names 

            - return true if it is possible to assign integers to variable names so as to satisfy all the given equations, or false otherwise 

            loop through the equation and then build a group for all the equals 
            and then do the same for the not equal and check if the find for both sides are not equal
            
        */


        parent.resize(26);
        std::iota(parent.begin(), parent.end(), 0);

        //for equal passes
        for (int i {}; i < equations.size(); i++){
            if (equations[i][1] == '='){
                unite(equations[i][0] - 'a', equations[i][3] - 'a');
            }
        }

        //for not equal passes
        for (int i {}; i < equations.size(); i++){
            if (equations[i][1] == '!'){
                if (find(equations[i][0] - 'a') == find(equations[i][3] - 'a')){
                    return false;
                }
            }
        }

        return true;
    }
};