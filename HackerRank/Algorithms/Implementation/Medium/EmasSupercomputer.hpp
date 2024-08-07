//
//  EmasSupercomputer.hpp
//  HackerRank
//
//  Created by Salvatore on 4/7/24.
//

#ifndef EmasSupercomputer_hpp
#define EmasSupercomputer_hpp

#include <stdio.h>

namespace EmasSupercomputer {

    struct Plus {
        int r, c;
        int dim;
        
        vector<pair<int, int>> occupied;
        
        Plus(int r, int c, int dim) {
            this->r = r;
            this->c = c;
            this->dim = dim;
            
            occupied = getOccupiedPoints();
        }
        
        bool overlap(const Plus& other) {
            auto points1 = other.occupied;
            
            // Check for any common points
            for (const auto& pt1 : points1) {
                for (const auto& pt2 : occupied) {
                    if (pt1 == pt2) {
                        return true;
                    }
                }
            }
            return false;
        }
        
        int totalSpaces() {
            return dim * 4 + 1;
        }
    private:
        std::vector<std::pair<int, int>> getOccupiedPoints() const {
            std::vector<std::pair<int, int>> points;
            // Center point
            points.emplace_back(r, c);
            // Vertical points
            for (int i = 1; i <= dim; ++i) {
                points.emplace_back(r - i, c); // Up
                points.emplace_back(r + i, c); // Down
            }
            // Horizontal points
            for (int i = 1; i <= dim; ++i) {
                points.emplace_back(r, c - i); // Left
                points.emplace_back(r, c + i); // Right
            }
            return points;
        }
        
        
    };

    bool isValid(vector<string> &grid, int r, int c, int dim, int rows, int cols) {
        
        int rr0 = r - dim, rr1 = r + dim;
        int cc0 = c - dim, cc1 = c + dim;
        
        if (rr0 < 0) return false;
        if (rr1 >= rows) return false;
        
        if (cc0 < 0) return false;
        if (cc1 >= cols) return false;
        
        return  grid[r][cc0] == 'G' &&
                grid[r][cc1] == 'G' &&
                grid[rr1][c] == 'G' &&
                grid[rr0][c] == 'G';
    }

    int twoPluses(vector<string> grid) {
        
        int rows = (int)grid.size();
        int cols = (int)grid.front().size();
        
        int maxDim = min (rows, cols);
        
        vector<Plus> pluses;
        
        for (int r = 0; r < rows; ++r){
            for (int c = 0; c < cols; ++c) {

                if (!(grid[r][c] == 'G')) continue;

                for (int d = 0; d < maxDim; ++d) {
                    if (!isValid(grid, r, c, d, rows, cols)) break;
                    pluses.push_back({r, c, d});
                }
            }
        }
        
        int maxValue = 0;
        for (int i = 0; i < pluses.size(); ++i)
            for (int j = i + 1; j < pluses.size(); ++j)
                if (!pluses[i].overlap(pluses[j])) {
                    int temp = pluses[i].totalSpaces() * pluses[j].totalSpaces();
                    maxValue = max(maxValue, temp);
                }

        return maxValue; //(pluses[0].totalSpaces()) * (pluses[1].totalSpaces());
    }

    void test()
    {
        string test_case = "03";
        string path = format_file_path_test(__FILE__);
        
        TestIO io = TestIO(path, test_case);
        
        string t_out;

        string first_multiple_input_temp;
        getline(io.input, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        //int m = stoi(first_multiple_input[1]);

        vector<string> grid(n);

        for (int i = 0; i < n; i++) {
            string grid_item;
            getline(io.input, grid_item);

            grid[i] = grid_item;
        }

        int result = twoPluses(grid);
        
        getline(io.output, t_out);
        assert(result == stoi(t_out), to_string(result) + " == " + t_out);
        
    }

}

#endif /* EmasSupercomputer_hpp */
