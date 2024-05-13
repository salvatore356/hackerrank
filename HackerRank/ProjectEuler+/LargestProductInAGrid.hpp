//
//  LargestProductInAGrid.hpp
//  HackerRank
//
//  Created by Salvatore on 13/5/24.
//

#ifndef LargestProductInAGrid_hpp
#define LargestProductInAGrid_hpp

#include <stdio.h>

namespace LargestProductInAGrid {

    long upMult(int r, int c, vector<vector<int>> &grid){
        if ( r < 4 ) return 0;
        long mult = 1;
        
        for (int i = 0; i < 4; ++i)
            mult *= grid[r - i][c];
        
        return mult;
    }

    long leftUpMult(int r, int c, vector<vector<int>> &grid){
        if ( r < 4  || c < 4) return 0;
        long mult = 1;
        
        for (int i = 0; i < 4; ++i)
            mult *= grid[r - i][c - i];
        
        return mult;
    }

    long rightUpMult(int r, int c, vector<vector<int>> &grid){
        if ( r < 4 || c + 4 >= grid[r].size()) return 0;
        long mult = 1;
        
        for (int i = 0; i < 4; ++i)
            mult *= grid[r - i][c + i];
        
        return mult;
    }

    long rightDownMult(int r, int c, vector<vector<int>> &grid){
        if ( r + 4 >= grid.size() || c + 4 >= grid[r].size()) return 0;
        long mult = 1;
        
        for (int i = 0; i < 4; ++i)
            mult *= grid[r + i][c + i];
        
        return mult;
    }


    long leftDownMult(int r, int c, vector<vector<int>> &grid){
        if ( r + 4 >= grid.size() || c < 4) return 0;
        long mult = 1;
        
        for (int i = 0; i < 4; ++i)
            mult *= grid[r + i][c - i];
        
        return mult;
    }

    long downMult(int r, int c, vector<vector<int>> &grid){
        if ( (r + 4) >= grid.size() ) return 0;
        long mult = 1;
        
        for (int i = 0; i < 4; ++i)
            mult *= grid[r + i][c];
        
        return mult;
    }

    long rightMult(int r, int c, vector<vector<int>> &grid){
        if ( (c + 4) >= grid.size()) return 0;
        long mult = 1;
        
        for (int i = 0; i < 4; ++i)
            mult *= grid[r][c + i];
        
        return mult;
    }

    long leftMult(int r, int c, vector<vector<int>> &grid){
        if ( c < 4) return 0;
        long mult = 1;
        
        for (int i = 0; i < 4; ++i)
            mult *= grid[r][c - i];
        
        return mult;
    }

    long largestProductInAGrid(vector<vector<int>> &grid) {
        long ans = 0;
        
        for (int r = 0; r < grid.size(); ++r) {
            for (int c = 0; c < grid[r].size(); ++c) {
                
                ans = max (ans , leftDownMult(r, c, grid));
                ans = max (ans , leftUpMult(r, c, grid));
                ans = max (ans , leftMult(r, c, grid));
                
                ans = max (ans , rightDownMult(r, c, grid));
                ans = max (ans , rightUpMult(r, c, grid));
                ans = max (ans , rightMult(r, c, grid));
                
                ans = max (ans , upMult(r, c, grid));
                ans = max (ans , downMult(r, c, grid));
            }
        }
        
        return ans;
    }


    void test() {
        
        string path = "Tests/ProjectEuler+/LargestProductInAGrid/";
        std::ifstream input(path  +  "input00.txt");
        std::ifstream output(path + "output00.txt");

        vector<vector<int>> grid(20);

        for (int i = 0; i < 20; i++) {
            grid[i].resize(20);

            string grid_row_temp_temp;
            getline(input, grid_row_temp_temp);

            vector<string> grid_row_temp = split(rtrim(grid_row_temp_temp));

            for (int j = 0; j < 20; j++) {
                int grid_row_item = stoi(grid_row_temp[j]);

                grid[i][j] = grid_row_item;
            }
        }
        
        long result = largestProductInAGrid(grid);
        
        string t_out;
        getline(output, t_out);
        assert(result == stol(t_out), to_string(result) + " == " + t_out);
    }
}

#endif /* LargestProductInAGrid_hpp */
