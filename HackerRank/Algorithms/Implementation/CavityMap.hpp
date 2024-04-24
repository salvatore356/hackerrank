//
//  CavityMap.hpp
//  HackerRank
//
//  Created by Salvatore on 24/4/24.
//

#ifndef CavityMap_hpp
#define CavityMap_hpp

#include <stdio.h>

namespace CavityMap {

    vector<string> cavityMap(vector<string> grid) {
        
        vector<string> ans = grid;
        
        for(int r = 1; r < grid.size() - 1; ++r) {
            
            for(int c = 1; c < grid[r].size() - 1; ++c){
                
                char current = grid[r][c];
                
                if(current > grid[r - 1][c] &&
                   current > grid[r + 1][c] &&
                   current > grid[r][c - 1] &&
                   current > grid[r][c + 1] )
                    ans[r][c] = 'X';
            }
                
        }
        
        return ans;
    }

    void test() {
        string path = "Tests/Algorithms/Implementation/CavityMap/";
        std::ifstream input(path  +  "input21.txt");
        std::ifstream output(path + "output21.txt");

        string n_temp;
        getline(input, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        vector<string> grid(n);

        for (int i = 0; i < n; i++) {
            string grid_item;
            getline(input, grid_item);

            grid[i] = grid_item;
        }

        vector<string> result = cavityMap(grid);

        string out;
        for (size_t i = 0; i < result.size(); i++) {
            
            getline(output, out);
            assert(result[i] == out, result[i] + " == " + out);
        }

    }
}

#endif /* CavityMap_hpp */
