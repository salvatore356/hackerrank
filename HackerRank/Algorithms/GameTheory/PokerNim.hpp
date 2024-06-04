//
//  PokerNim.hpp
//  HackerRank
//
//  Created by Salvatore on 4/6/24.
//

#ifndef PokerNim_hpp
#define PokerNim_hpp

#include <stdio.h>

namespace PokerNim {

    string pokerNim(int k, vector<int> c) {
        int total = 0;
        
        for (int i = 0; i < c.size(); ++i)
            total ^= c[i];
        
        return total ? "First" : "Second";
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

            int k = stoi(first_multiple_input[1]);

            string c_temp_temp;
            getline(input, c_temp_temp);

            vector<string> c_temp = split(rtrim(c_temp_temp));

            vector<int> c(n);

            for (int i = 0; i < n; i++) {
                int c_item = stoi(c_temp[i]);

                c[i] = c_item;
            }

            string result = pokerNim(k, c);

            getline(output, t_out);
            assert(result == t_out, result + " == " + t_out);
        }
    }
}

#endif /* PokerNim_hpp */
