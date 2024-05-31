//
//  AChessboardGame.hpp
//  HackerRank
//
//  Created by Salvatore on 31/5/24.
//

#ifndef AChessboardGame_hpp
#define AChessboardGame_hpp

#include <stdio.h>

namespace AChessboardGame {

    string chessboardGame(int x, int y) {
        return (x-1) % 4 <= 1 && (y-1) % 4 <= 1 ? "Second" : "First";
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

            int x = stoi(first_multiple_input[0]);

            int y = stoi(first_multiple_input[1]);

            string result = chessboardGame(x, y);
            getline(output, t_out);
            assert(result == t_out, result + " == " + t_out);

        }

    }
}

#endif /* AChessboardGame_hpp */
