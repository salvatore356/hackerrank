//
//  TheBombermanGame.hpp
//  HackerRank
//
//  Created by Salvatore on 25/6/24.
//

#ifndef TheBombermanGame_hpp
#define TheBombermanGame_hpp

#include <stdio.h>

namespace TheBombermanGame {

    void explode(vector<string> &grid, int r, int c) {
        
        grid[r][c] = '.';
        
        if (r + 1 < grid.size() && grid[r + 1][c] != 'M')
            grid[r + 1][c] = '.';
        
        if (r - 1 >= 0 && grid[r - 1][c] != 'M')
            grid[r - 1][c] = '.';
        
        if (c - 1 >= 0 && grid[r][c - 1] != 'M')
            grid[r][c - 1] = '.';
        
        if (c + 1 < grid.front().size() && grid[r][c + 1] != 'M')
            grid[r][c + 1] = '.';
    }

    void checkMatrix(vector<string> &grid, int step) {
        
        
        bool planting = (step % 2 ) == 0; // plant
        
        for (int r = 0; r < grid.size(); ++r) {
            for(int c = 0; c < grid.front().size(); ++c){
                if (grid[r][c] > 'M')
                    --grid[r][c];
                else if (grid[r][c] == 'M')
                    explode(grid, r, c);
                else if (planting && grid[r][c] == '.')
                    grid[r][c] = 'O';
            }
        }
        
    }
    
    void fixMatrix(vector<string> &grid) {
        for (int r = 0; r < grid.size(); ++r) {
            for(int c = 0; c < grid.front().size(); ++c){
                if(grid[r][c] != '.') grid[r][c] = 'O';
                    
            }
        }
    }
    void fillMatrix(vector<string> &grid){
        for (int r = 0; r < grid.size(); ++r)
            for(int c = 0; c < grid.front().size(); ++c)
                grid[r][c] = 'O';
    }
    
    vector<string> bomberMan(int n, vector<string> grid) {
        if (n == 1) return grid;
        if (n % 2 == 0) {
            fillMatrix(grid);
            return grid;
        }
        
        int steps = (n % 4 == 1) ? 5 : 3;
        
        for (int i = 1; i <= steps; ++i) {
            checkMatrix(grid, i);
        }
        
        fixMatrix(grid);
        return grid;
    }

    void test() {
        string test_case = "25";
        string path = format_file_path_test(__FILE__);
        
        TestIO io = TestIO(path, test_case);
        
        string t_out;

        string first_multiple_input_temp;
        getline(io.input, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int r = stoi(first_multiple_input[0]);

        //int c = stoi(first_multiple_input[1]);

        int n = stoi(first_multiple_input[2]);

        vector<string> grid(r);

        for (int i = 0; i < r; i++) {
            string grid_item;
            getline(io.input, grid_item);

            grid[i] = grid_item;
        }

        vector<string> result = bomberMan(n, grid);

        for (size_t i = 0; i < result.size(); i++) {
            getline(io.output, t_out);
            assert(result[i] == t_out, result[i] + " == " + t_out);
            
            /*fout << result[i];

            if (i != result.size() - 1) {
                fout << "\n";
            }*/
        }
    }
}

#endif /* TheBombermanGame_hpp */
