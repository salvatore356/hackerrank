//
//  TowerBreakers.hpp
//  HackerRank
//
//  Created by Salvatore on 31/5/24.
//

#ifndef TowerBreakers_hpp
#define TowerBreakers_hpp

#include <stdio.h>

namespace TowerBreakers {

    int towerBreakers(int n, int m) {
        return n % 2 == 0 || m == 1 ? 2 : 1;
    }

    void test() {
        string test_case = "00";
        string path = "Tests/Algorithms/GameTheory/" + remove_extension(__FILE_NAME__) + "/";
        std::ifstream input(path  +  "input" + test_case + ".txt");
        std::ifstream output(path + "output" + test_case + ".txt");

        string t_out;

        string t_temp;
        getline(input, t_temp);

        int t = stoi(ltrim(rtrim(t_temp)));

        for (int t_itr = 0; t_itr < t; t_itr++) {
            string first_multiple_input_temp;
            getline(input, first_multiple_input_temp);

            vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

            int n = stoi(first_multiple_input[0]);

            int m = stoi(first_multiple_input[1]);

            int result = towerBreakers(n, m);
            getline(output, t_out);
            assert(result == stoi(t_out), to_string(result) + " == " + t_out);
            
        }
    }
}

#endif /* TowerBreakers_hpp */
