//
//  GridChallenge.hpp
//  HackerRank
//
//  Created by Salvatore on 23/5/24.
//

#ifndef GridChallenge_hpp
#define GridChallenge_hpp

#include <stdio.h>

namespace GridChallenge {

    string gridChallenge(vector<string> grid) {
        
        for (auto &s : grid)
            sort(s.begin(), s.end());

        for (int c = 0; c < grid.front().size(); ++c) {
            for (int r = 1; r < grid.size(); ++r) {
                if (grid[r][c] < grid[r-1][c])
                    return "NO";
            }
        }
        
        return "YES";
    }

    void test() {
        string test_case = "00";
        string path = "Tests/Algorithms/Greedy/" + remove_extension(__FILE_NAME__) + "/";
        std::ifstream input(path  +  "input" + test_case + ".txt");
        std::ifstream output(path + "output" + test_case + ".txt");

        string t_temp, t_out;
        getline(input, t_temp);

        int t = stoi(ltrim(rtrim(t_temp)));

        for (int t_itr = 0; t_itr < t; t_itr++) {
            string n_temp;
            getline(input, n_temp);

            int n = stoi(ltrim(rtrim(n_temp)));

            vector<string> grid(n);

            for (int i = 0; i < n; i++) {
                string grid_item;
                getline(input, grid_item);

                grid[i] = grid_item;
            }

            string result = gridChallenge(grid);
            getline(output, t_out);
            assert(result == t_out, result + " == " + t_out);
            
        }

        
    }
}

#endif /* GridChallenge_hpp */
