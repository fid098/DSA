class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        /*
            0 represents forested
            1 represents farmland

            there are rectangular areas of hectares that consist of farmland only called groups
            no two groups are adjacent, one farmland in one group is not adjacent to another farmland in another group

            find the coordinates of the top left and bottom right corner of each group of farmland

            we could flood fill for each group, and track the minr, minc, maxr and maxc as we go and return that 

            or

            find the left corner(above or left isnt 1) or its column 0

            Find the bottom-right corner from there.
            Walk down from (r, c) while the cells are 1. The last one gives you r2.
            Walk right from (r, c) while the cells are 1. The last one gives you c2.
            Because it's a solid rectangle, the corner is (r2, c2).
        */

        std::vector<std::vector<int>> result;
        int ROWS = land.size();
        int COLS = land[0].size();
        
        for (int r {}; r < ROWS; r++){
            for (int c {}; c < COLS; c++){
                bool topClear = (r == 0 || land[r - 1][c] == 0);
                bool leftClear = (c == 0 || land[r][c - 1] == 0);
                if (land[r][c] == 1 && topClear && leftClear){
                        int r2 = r;
                        int c2 = c;

                        while (r2 + 1 < ROWS && land[r2 + 1][c] == 1){
                            r2 = r2 + 1;
                        }

                        while (c2 + 1 < COLS && land[r][c2 + 1] == 1){
                            c2 = c2 + 1;
                        }

                        result.push_back({r, c, r2, c2});
                    }
                }
        }

        return result;

    }
};