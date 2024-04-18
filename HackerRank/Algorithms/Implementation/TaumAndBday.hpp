//
//  TaumAndBday.hpp
//  HackerRank
//
//  Created by Salvatore on 18/4/24.
//

#ifndef TaumAndBday_hpp
#define TaumAndBday_hpp

#include <stdio.h>

namespace TaumAndBday {
    long taumBday(int b, int w, int bc, int wc, int z) {
        long whiteCost = min(wc, bc + z), blackCost = min (bc, wc + z);
        return w * whiteCost + b * blackCost;
    }

    void test() {
        string path = "Tests/Algorithms/Implementation/TaumAndBday/";
        std::ifstream input(path  +  "input00.txt");
        std::ifstream output(path + "output00.txt");

        string t_temp;
        getline(input, t_temp);

        int t = stoi(ltrim(rtrim(t_temp)));

        for (int t_itr = 0; t_itr < t; t_itr++) {
            string first_multiple_input_temp;
            getline(input, first_multiple_input_temp);

            vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

            int b = stoi(first_multiple_input[0]);

            int w = stoi(first_multiple_input[1]);

            string second_multiple_input_temp;
            getline(input, second_multiple_input_temp);

            vector<string> second_multiple_input = split(rtrim(second_multiple_input_temp));

            int bc = stoi(second_multiple_input[0]);

            int wc = stoi(second_multiple_input[1]);

            int z = stoi(second_multiple_input[2]);

            long result = taumBday(b, w, bc, wc, z);
            
            string out1;
            getline(output, out1);
            
            assert(result == stol(out1), to_string(result) + " == " + out1);
            
        }

        

        
    }
}

#endif /* TaumAndBday_hpp */
