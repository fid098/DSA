class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        /*
            - given string array recipes
            - ith recipe = recipe[i]
            - IF YOU HAVE ALL THE NEEDED INGREDIENTS you can create the recipe
            - a recipe can also be an ingredient for other recipes (ingredient[i] could be in recipes)
            - also given an array supplies that contains all the initial ingredients(which are infinite)
            
            return in any order, a list of all the recipes that can be created
            - two recipies could contain eachother in their ingredients 
            
            bread - yeast, flour
            
            {bread: yeast, flour}
            
            
            recipes = ["bread","sandwich"], ingredients = [["yeast","flour"],["bread","meat"]], supplies = ["yeast","flour","meat"]
            
            {bread: yeast, flour
            sandwich: bread, meat}
             
            supplies: yeast, flour, meat, bread
             
            recipes = ["bread","sandwich","burger"], ingredients = [["yeast","flour"],["bread","meat"],["sandwich","meat","bread"]], supplies = ["yeast","flour","meat", bread, sandwich, burget]
             
             
            Hint:
            
                precondition
                
                    map: ingredient -> vector of recipe
                    map: recipe -> int indegree
                    
                    indegree and outdegree
                    
                    indegree = 0
                    
                set up:
                     let n = number of size of array
                     for i: 0 -> n:
                        for each ingredient:
                            if not in supply:
                                mp[ingredient].psuh_back(recipe)
                                indegrees[recipe] += 1
        
        
                toposort:
                    for i: 0 to n:
                        IF INDEGREE[I] = 0:
                            add recipe to queue
                            
                    while (!q.empty) {
                        pop the recipe
                        add to result
                        // check if this recipe is an ingredient for other recipes
                        for (rec : mp[popped]) {
                            indegree[rec]--;
                            if (indegreee[rec] == 0) q.push(rec)
                        }
                    }
        */
        
        
        using namespace std;

        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> indegree;
        queue<string> q;
        vector<string> result;
        unordered_set<string> set_supplies(supplies.begin(), supplies.end());

        for (int i {}; i < recipes.size(); i++){
            indegree[recipes[i]] = 0;
        }
        
        for (int i {}; i < ingredients.size(); i++){
            for (int j {}; j < ingredients[i].size(); j++){
                string ing = ingredients[i][j];
                if (!set_supplies.count(ing)){
                    graph[ing].push_back(recipes[i]);
                    indegree[recipes[i]]++;
                }
            }
        }
        /*
         go through all recipes
         check if the to indegree for the recipe is 0 
         then add to q
        */
        
        for (auto [key, val] : indegree){
            if (val == 0){
                q.push(key);
            }
        }
        
        
        while (!q.empty()){
            string node = q.front();
            q.pop();
            result.push_back(node);
            //weve popped the recipe
            
            for (const string nei : graph[node]){
                //for each recipe where this is an ingredient
                indegree[nei]--;
                
                if (indegree[nei] == 0){
                    q.push(nei);
                }
            }
        }
        
        return result;
        
    }
};