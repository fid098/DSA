class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        std::unordered_set<std::string> trapped(deadends.begin(), deadends.end());
        std::unordered_set<std::string> visited;
        std::queue<std::string> q;
        if (trapped.count("0000")){
            return -1;
        }
        q.push("0000");
        visited.insert("0000");
        int steps {0};

        while (!q.empty()){
            int n = q.size();
            for (int i {0}; i < n; i++){
                std::string num = q.front();
                q.pop();

                if (num == target){
                    return steps;
                }

                //generate neighbours;
                for (int pos {0}; pos < num.size(); pos++){
                    char orig = num[pos];
                    if (orig == '9'){
                        num[pos] = '0';
                    }
                    else{
                        num[pos] = orig + 1;
                    }
                    std::string up = num;
                    if (orig == '0'){
                        num[pos] = '9';
                    }
                    else{
                        num[pos] = orig - 1;
                    }
                    std::string down = num;
                    //back to original for the next index 
                    num[pos] = orig;
                    std::vector<std::string> neighbours = {up, down};

                    for (auto nei : neighbours){
                        if (trapped.count(nei) || visited.count(nei)){
                            continue;
                        }
                        q.push(nei);
                        visited.insert(nei);
                    }
                }
            }

            steps++;
        }
        return -1;
    }
};