//
//  GameOfStones.hpp
//  HackerRank
//
//  Created by Salvatore on 30/5/24.
//

#ifndef GameOfStones_hpp
#define GameOfStones_hpp

#include <stdio.h>

namespace GameOfStones {

    string gameOfStones(int n) {
        return n % 7 <= 1 ? "Second" : "First";
    }

    void test() {
        string test_case = "01";
        string path = "Tests/Algorithms/GameTheory/" + remove_extension(__FILE_NAME__) + "/";
        std::ifstream input(path  +  "input" + test_case + ".txt");
        std::ifstream output(path + "output" + test_case + ".txt");

        string t_out;

        string t_temp;
        getline(input, t_temp);

        int t = stoi(ltrim(rtrim(t_temp)));

        for (int t_itr = 0; t_itr < t; t_itr++) {
            string n_temp;
            getline(input, n_temp);

            int n = stoi(ltrim(rtrim(n_temp)));

            string result = gameOfStones(n);
            getline(output, t_out);
            assert(result == t_out, result + " == " + t_out);
            
        }
    }
}

#endif /* GameOfStones_hpp */
